#include "image-sprite.h"

#include <raylib.h>
#include <string>
#include <vector>

ImageSprite::ImageSprite(const std::vector<std::string> &texture_path_strings,
                         const int x_pos, const int y_pos)
    : m_pos_x{x_pos}, m_pos_y{y_pos}
{
    loadTextures(texture_path_strings);
}

ImageSprite::~ImageSprite() { unloadTextures(m_loaded_textures); }

void ImageSprite::drawSprite(const int texture_index)
{
    DrawTexture(m_loaded_textures.at(texture_index), m_pos_x, m_pos_y, WHITE);
}

void ImageSprite::drawSprite(const int x_pos, const int y_pos,
                             const int texture_index)
{
    m_pos_x = x_pos;
    m_pos_y = y_pos;

    DrawTexture(m_loaded_textures.at(texture_index), m_pos_x, m_pos_y, WHITE);
}

void ImageSprite::loadTextures(const std::vector<std::string> &texture_samples)
{
    for (const auto texture_path : texture_samples)
    {
        m_loaded_textures.push_back(LoadTexture(texture_path.c_str()));
    }
}

void ImageSprite::unloadTextures(std::vector<Texture2D> &texture_samples)
{
    for (auto current_texture : texture_samples)
    {
        UnloadTexture(current_texture);
    }
}
