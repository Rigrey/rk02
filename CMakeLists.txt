cmake_minimum_required(VERSION 3.10)
project(MyProxyApp)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(MyProxyApp main.cpp)

add_library(Proxy Proxy.cpp)

target_link_libraries(MyProxyApp Proxy)
