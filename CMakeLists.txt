cmake_minimum_required(VERSION 3.5.1)
project(assn01)
include_directories(headers)

file(GLOB SOURCES "*.cpp")

add_executable(assn01.out ${SOURCES})