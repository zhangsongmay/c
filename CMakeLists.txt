cmake_minimum_required(VERSION 3.17)
project(zscsokect C)

set(CMAKE_C_STANDARD 99)

aux_source_directory(source DIR_SOURCE)
include_directories(${DIR_SOURCE})
add_executable(zscsocket ${DIR_SOURCE})

# 指定安装路径
install (TARGETS zscsocket DESTINATION bin)
#install (FILES source/util.h DESTINATION include)
#install (FILES source/constant.h DESTINATION include)
#install (FILES source/zssocket.h DESTINATION include)