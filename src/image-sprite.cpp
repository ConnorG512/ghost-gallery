#include "image-sprite.h"

#include <raylib.h>
#include <string>
#include <vector>

ImageSprite::ImageSprite(const std::vector<std::string>& texture_path_strings) { loadTextures(texture_path_strings); }

ImageSprite::~ImageSprite() { unloadTextures(m_loaded_textures); }

void ImageSprite::drawSprite(const std::array<int, 2> xy_pos, const int texture_index)
{
    DrawTexture(m_loaded_textures.at(texture_index), xy_pos.at(0), xy_pos.at(1), WHITE);
}

void ImageSprite::loadTextures(const std::vector<std::string>& texture_samples)
{
    for (const auto texture_path : texture_samples)
    {
        m_loaded_textures.push_back(LoadTexture(texture_path.c_str()));
    }
}

void ImageSprite::unloadTextures(const std::vector<Texture2D>& texture_samples)
{
    for (auto current_texture : texture_samples)
    {
        UnloadTexture(current_texture);
    }
}
