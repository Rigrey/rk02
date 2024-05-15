cmake_minimum_required(VERSION 3.10)
project(MyProxyApp)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Добавляем исполняемый файл main.cpp
add_executable(MyProxyApp main.cpp)

# Добавляем библиотеку Proxy.cpp
add_library(Proxy Proxy.cpp)

# Линкуем библиотеку к исполняемому файлу
target_link_libraries(MyProxyApp Proxy)
