#include "enemy.h"
#include "player.h"
#include "../random-generation.h"
#include "../input-handler.h"
#include <array>

namespace 
{
  constexpr std::array<int , 2> score_range { 25, 75 };
}

Enemy::Enemy
(
  const int x_pos,
  const int y_pos
) 
  : Entity { { "assets/image/entity/enemy/ghost/ghost-1.png" }, 2, 2, x_pos, y_pos }
  , score_to_give { RandomGeneration::NumberBetween( score_range.at( 0 ), score_range.at( 1 ))} { }

void Enemy::attackPlayer( Player& current_player )
{
  if ( m_tick_component.hasHitTickThreshold()) {
    current_player.health_component.reduceHealth( damage_component.CalculateDamage());
    respawnEnemy();
  }
}

void Enemy::respawnEnemy()
{
  moveSprite(RandomGeneration::NumberBetween( 100, 1400 ), RandomGeneration::NumberBetween( 200, 750 )); 
  changeEnemyGivenScore();
  m_tick_component.resetTickCount();
}

void Enemy::collidedWithPlayer( Player& current_player )
{
  if ( collision.isCollidingWith( current_player.collision.m_collision_shape ))
  {
    current_player.sprite.drawSprite( 1 );

    using enum InputHandler::ButtonPress;
    if ( InputHandler::receiveInput() == left_mouse )
    {
      respawnEnemy();
      current_player.score_component.increaseScore( score_to_give );
    }
  }
}

void Enemy::incrementAttackClock( Player& current_player )
{
  m_tick_component.incrementTickCount();
  if ( m_tick_component.hasHitTickThreshold())
  {
    attackPlayer( current_player );
  }
}

void Enemy::changeEnemyGivenScore()
{
  score_to_give = RandomGeneration::NumberBetween( score_range.at( 0 ), score_range.at( 1 ));
}
