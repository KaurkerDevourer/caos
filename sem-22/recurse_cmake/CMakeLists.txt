cmake_minimum_required(VERSION 3.10)
project(Main)

# Добавляем подкаталог с библиотекой
add_subdirectory(lib)

# Создаем исполняемый файл
add_executable(Main main.cpp)

# Связываем с библиотекой
target_link_libraries(Main MathUtils)
