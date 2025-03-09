cmake_minimum_required(VERSION 3.10)
project(Main)

# Создание динамической библиотеки
add_library(MathUtils SHARED math_utils/math_utils.cpp)

# Указание пути к заголовочным файлам
target_include_directories(MathUtils PUBLIC math_utils)

add_executable(Main main.cpp)

# Связывание с библиотекой
target_link_libraries(Main MathUtils)
