#pragma once

#include "../image-sprite.h"
#include "../collision-shape.h"
#include "../health-component.h"

#include <raylib.h>
#include <string>

class Entity 
{
  public:
    Entity( const int pos_x, const int pos_y, const std::vector<std::string>& texture_paths );
    Entity( const int pos_x, const int pos_y, const bool is_hidden, const std::vector<std::string>& texture_paths );
    Entity( const int max_health, const int pos_x, const int pos_y, const std::vector<std::string>& texture_paths );
    virtual ~Entity();

    void drawToScreen( const int texture_index = 0 );
    void drawToScreen( const int texture_index, const int pos_x, const int pos_y );

    bool checkCollision( const Rectangle& collider );
    
    void setHidden( bool is_hidden );
    bool isHidden();

    Rectangle& getCollision();
    
    HealthComponent health_component { 8, 8 };

    enum class EntityType 
    {
      neutral,
      friendly,
      hostile
    };
    virtual EntityType getEntityType();

  protected:
    int m_pos_x { 0 };
    int m_pos_y { 0 };
    bool m_is_hidden { false };
    ImageSprite m_sprite;
    CollisionShape m_collision { m_pos_x, m_pos_y, 128, 128 };
};
