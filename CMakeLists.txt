cmake_minimum_required(VERSION 3.8)
project(Axpoi)

set(CMAKE_C_STANDARD 99)

set(SOURCE_FILES axpoi.c consts.h conf/config.c conf/config.h utils/list/list.c utils/list/list.h utils/filter_char.h)
add_executable(Axpoi ${SOURCE_FILES})