cmake_minimum_required(VERSION 3.0.0)

set(OSBitness x32)
if(CMAKE_SIZEOF_VOID_P EQUAL 8)
    set(OSBitness x64)
endif()

project(hazel VERSION 0.0.1)

add_library(${PROJECT_NAME} SHARED Hazel/src/Hazel.h Hazel/src/Hazel/Application.cpp Hazel/src/Hazel/Application.h Hazel/src/Hazel/Core.h)

set_target_properties(
    ${PROJECT_NAME}
    PROPERTIES LIBRARY_OUTPUT_DIRECTORY 
    ${CMAKE_BINARY_DIR}/bin/${CMAKE_VS_PLATFORM_NAME}${CMAKE_BUILD_TYPE}-${OSBitness}/${PROJECT_NAME}/)


project(sandbox VERSION 0.0.1)

add_executable(sandbox Sandbox/sandboxApp.cpp Hazel/src/Hazel.h)

include_directories(${CMAKE_SOURCE_DIR}/Hazel/src/)
set_target_properties(
    ${PROJECT_NAME} 
    PROPERTIES RUNTIME_OUTPUT_DIRECTORY 
    ${CMAKE_BINARY_DIR}/bin/${CMAKE_VS_PLATFORM_NAME}${CMAKE_BUILD_TYPE}-${OSBitness}/${PROJECT_NAME}/)

    # target_include_directories(${PROJECT_NAME} Hazel/src/Hazel.h)
    # add_subdirectory(${CMAKE_SOURCE_DIR}Hazel/src/Hazel.h)

    # LINKE COMPILED LIBRARY
    # find_library(hazel ${CMAKE_BINARY_DIR}/bin/${CMAKE_VS_PLATFORM_NAME}${CMAKE_BUILD_TYPE}/hazel/libhazel.so)
target_link_libraries(${PROJECT_NAME} PRIVATE hazel)


