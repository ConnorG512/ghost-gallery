cmake_minimum_required(VERSION 3.31)
project(App CXX)

set(CMAKE_CXX_STANDARD 23)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(SOURCE_FILES
  src/entities/collectable/candy-collectable.cpp
  src/entities/collectable/coin-collectable.cpp
  src/entities/collectable/collectable.cpp
  src/entities/collectable/heart-collectable.cpp
  src/entities/components/score-component.cpp
  src/entities/components/health-component.cpp
  src/entities/components/positional-component.cpp
  src/entities/components/damage-component.cpp
  src/entities/components/tick-component.cpp
  src/entities/components/user-input-component.cpp
  src/entities/entity.cpp
  src/entities/player.cpp
  src/entities/enemy.cpp
  src/ui/ui.cpp
  src/ui/ui-gameplay.cpp
  src/ui/ui-splash.cpp
  src/spawner/spawn-manager.cpp
  src/spawner/spawn-manager-collectable.cpp
  src/spawner/spawn-manager-enemy.cpp
  src/util/random-generation.cpp
  src/main.cpp
  src/collision-shape.cpp
  src/image-sprite.cpp
  src/manager/window-manager.cpp
  src/manager/game-manager.cpp
  src/manager/audio-manager.cpp
  src/game-state/gamestate-base.cpp
  src/game-state/gamestate-splash.cpp
  src/game-state/gamestate-gameplay.cpp
)

#Creating executable:
if(WIN32)
  add_executable(app WIN32 ${SOURCE_FILES})
else()
  add_executable(app ${SOURCE_FILES})
endif()

# Setting a custom include directory
target_include_directories(app PRIVATE "${CMAKE_SOURCE_DIR}/include")

# Compile options:
if(MINGW)
  # Statically link standard library when compiling with the MinGW-W64 compiler:
  set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -static-libgcc -static-libstdc++")
  set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -static-libgcc")
elseif (UNIX AND NOT APPLE)
  target_compile_options(app PRIVATE -fsanitize=address,undefined -ggdb) # Better GDB symbols, fsanitize 
  target_link_options(app PRIVATE -fsanitize=address,undefined)
endif()

# Linking libraries:
find_package(raylib REQUIRED)
target_link_libraries(app PRIVATE raylib)

# Installation Directory:
install(TARGETS app RUNTIME DESTINATION bin)
