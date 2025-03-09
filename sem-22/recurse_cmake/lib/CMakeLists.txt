cmake_minimum_required(VERSION 3.10)
project(MathUtils)

# Создаем статическую библиотеку
add_library(MathUtils STATIC src/math_utils.cpp)

# Указываем путь к заголовочным файлам
target_include_directories(MathUtils PUBLIC include)
