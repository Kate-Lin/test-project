cmake_minimum_required(VERSION 3.17.3)
project(new_json)

set(CMAKE_BUILD_TYPE Debug)
set(CMAKE_CXX_FLAGS -std=c++11)

include_directories(${CMAKE_CURRENT_SOURCE_DIR}/include)
include_directories(${CMAKE_CURRENT_SOURCE_DIR}/jsonhead)

AUX_SOURCE_DIRECTORY(./src SRC_LIST)
AUX_SOURCE_DIRECTORY(./jsonsrc JSON_SRC_LIST)


add_executable(new_json ${SRC_LIST} ${JSON_SRC_LIST})   
target_link_libraries(new_json  pthread boost_system)  