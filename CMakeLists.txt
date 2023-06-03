cmake_minimum_required(VERSION 3.20)

include_directories(src)
include_directories(libFiles)
include_directories(helperFiles)
include_directories(test)

add_subdirectory(test/googletest)

ADD_EXECUTABLE(main
    src/main.cpp
    src/entity.cpp
    src/character.cpp
    src/monster.cpp
    src/game.cpp
    src/room.cpp
    src/item.cpp
    src/cleric.cpp
    src/rogue.cpp
    src/warrior.cpp
    src/wizard.cpp
)

ADD_EXECUTABLE(tests
    test/roomFunctionTest.cpp
)

target_link_libraries(tests gtest gtest_main)