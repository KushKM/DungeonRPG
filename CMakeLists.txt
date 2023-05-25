cmake_minimum_required(VERSION 3.20)

include_directories(src)
include_directories(libFiles)
include_directories(helperFiles)

ADD_EXECUTABLE(main
    src/main.cpp
    src/entity.cpp
    src/character.cpp
    src/monster.cpp
    src/game.cpp
    src/room.cpp
    src/item.cpp
)

