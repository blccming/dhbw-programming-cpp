cmake_minimum_required(VERSION 3.20)

project(gameboard)

add_definitions(
    -Wall  # enable all warnings
)

set(SOURCE_FILES
    main.cpp
    gameboard.h
    gameboard.cpp
)

add_executable(
    ${PROJECT_NAME}
    ${SOURCE_FILES}
)
