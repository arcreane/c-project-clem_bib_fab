cmake_minimum_required(VERSION 3.11) # FetchContent is available in 3.11+
project(towerDefense)

# Dependencies
find_package(raylib 4.0.0 QUIET) # QUIET or REQUIRED
if (NOT raylib_FOUND) # If there's none, fetch and build raylib
    include(FetchContent)
    FetchContent_Declare(
            raylib
            URL https://github.com/raysan5/raylib/archive/refs/tags/4.0.0.tar.gz
    )
    FetchContent_GetProperties(raylib)
    if (NOT raylib_POPULATED) # Have we downloaded raylib yet?
        set(FETCHCONTENT_QUIET NO)
        FetchContent_Populate(raylib)
        set(BUILD_EXAMPLES OFF CACHE BOOL "" FORCE) # don't build the supplied examples
        add_subdirectory(${raylib_SOURCE_DIR} ${raylib_BINARY_DIR})
    endif()
endif()

# Our Project

add_executable(${PROJECT_NAME} src/launcher/main.cpp src/animation/GameLoop.cpp src/animation/GameLoop.h src/controller/MainViewController.cpp src/controller/MainViewController.h src/entities/Tower.cpp src/entities/Tower.h src/entities/Monster.cpp src/entities/Monster.h src/graphics/GameMap.cpp src/graphics/GameMap.h src/graphics/SpriteSheet.cpp src/graphics/SpriteSheet.h src/model/block.cpp src/model/block.h src/tile/TileMapManager.cpp src/tile/TileMapManager.h src/entities/Projectile.cpp src/entities/Projectile.h src/entities/InfoEntities.cpp src/entities/InfoEntities.h)
#set(raylib_VERBOSE 1)
target_link_libraries(${PROJECT_NAME} raylib)

# Web Configurations
if (${PLATFORM} STREQUAL "Web")
    # Tell Emscripten to build an example.html file.
    set_target_properties(${PROJECT_NAME} PROPERTIES SUFFIX ".html")
endif()

# Checks if OSX and links appropriate frameworks (Only required on MacOS)
if (APPLE)
    target_link_libraries(${PROJECT_NAME} "-framework IOKit")
    target_link_libraries(${PROJECT_NAME} "-framework Cocoa")
    target_link_libraries(${PROJECT_NAME} "-framework OpenGL")
endif()