﻿# CMakeList.txt: проект CMake для MyAtoi; включите исходный код и определения,
# укажите здесь логику для конкретного проекта.
#
cmake_minimum_required (VERSION 3.8)

project ("MyAtoi")

# Добавьте источник в исполняемый файл этого проекта.
add_executable (MyAtoi "MyAtoi.cpp" "MyAtoi.h")

if (CMAKE_VERSION VERSION_GREATER 3.12)
  set_property(TARGET MyAtoi PROPERTY CXX_STANDARD 20)
endif()

# TODO: Добавьте тесты и целевые объекты, если это необходимо.
