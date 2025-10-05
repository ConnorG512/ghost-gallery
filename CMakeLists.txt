cmake_minimum_required(VERSION 3.31)

project(App CXX)

set(CMAKE_CXX_STANDARD 23)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(app 
  src/main.cpp
  src/window.h
  src/window.cpp
  src/player.h
  src/player.cpp
  src/image-sprite.h
  src/image-sprite.cpp
  src/game-manager.h
  src/game-manager.cpp
  src/text-render.h
  src/text-render.cpp
  src/entity.h
  src/entity.cpp
  src/health-component.h
  src/health-component.cpp
  src/collision-shape.h
  src/collision-shape.cpp
  src/random-generation.h
  src/random-generation.cpp
)

find_package(raylib REQUIRED)
target_link_libraries(app PRIVATE raylib)

install(TARGETS app RUNTIME DESTINATION bin)
