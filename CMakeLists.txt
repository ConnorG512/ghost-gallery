cmake_minimum_required(VERSION 3.31)

project(App CXX)

set(CMAKE_CXX_STANDARD 23)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(app 
  src/main.cpp
  src/window.h
  src/window.cpp
  src/entities/player.h
  src/entities/player.cpp
  src/image-sprite.h
  src/image-sprite.cpp
  src/game-manager.h
  src/game-manager.cpp
  src/text-render.h
  src/text-render.cpp
  src/entities/entity.h
  src/entities/entity.cpp
  src/health-component.h
  src/health-component.cpp
  src/collision-shape.h
  src/collision-shape.cpp
  src/random-generation.h
  src/random-generation.cpp
  src/tick-manager.h
  src/tick-manager.cpp
  src/input-handler.h
  src/input-handler.cpp
  src/gamestate/gamestate-base.h
  src/gamestate/gamestate-base.cpp
  src/gamestate/gamestate-gameplay.h
  src/gamestate/gamestate-gameplay.cpp
  src/gamestate/gamestate-splash.h
  src/gamestate/gamestate-splash.cpp
  src/entities/heart-collectable.h
  src/entities/heart-collectable.cpp
  src/entities/enemy.h
  src/entities/enemy.cpp
  src/score-manager.h
  src/score-manager.cpp
  src/damage-component.h
  src/damage-component.cpp
  src/entities/coin-collectable.h
  src/entities/coin-collectable.cpp
)

find_package(raylib REQUIRED)
target_link_libraries(app PRIVATE raylib)

install(TARGETS app RUNTIME DESTINATION bin)
