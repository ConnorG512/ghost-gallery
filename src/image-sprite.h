#pragma once

#include <array>
#include <raylib.h>
#include <string>
#include <vector>

class ImageSprite
{
  public:
    ImageSprite(const std::vector<std::string> &texture_path_strings);
    ~ImageSprite();

    void drawSprite(const std::array<int, 2> xy_pos = {0, 0},
                    const int texture_index = 0);

  private:
    std::vector<Texture2D> m_loaded_textures{};

    void loadTextures(const std::vector<std::string> &texture_samples);
    void unloadTextures(const std::vector<Texture2D> &texture_samples);
};
