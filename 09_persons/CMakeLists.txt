cmake_minimum_required(VERSION 3.20)

project(persons)

add_definitions(
    -Wall  # enable all warnings
)

set(SOURCE_FILES
    main.cpp
    person.h
    person.cpp
    student.h
    student.cpp
)

add_executable(
    ${PROJECT_NAME}
    ${SOURCE_FILES}
)
