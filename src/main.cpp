#include <raylib.h>

int main (int argc, char *argv[]) {
  
  constexpr int width = 800;
  constexpr int height = 600;
  constexpr int fps_limit = 60;

  InitWindow(width, height, "Window");
  SetTargetFPS(fps_limit);

  while (!WindowShouldClose()) {
    BeginDrawing();
    ClearBackground(WHITE);
    DrawText("Hello raylib", 800 / 2, 600 / 2, 32, LIGHTGRAY);
    EndDrawing();
  }
  
  CloseWindow();
  
  return 0;
}
