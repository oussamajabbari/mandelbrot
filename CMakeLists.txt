cmake_minimum_required(VERSION 2.6)

set (PROJECT_NAME mandelbrot)
set (EXECUTABLE_NAME ${PROJECT_NAME})

# Declaration du projet
project(${PROJECT_NAME})

# Path de l'executable
set(EXECUTABLE_OUTPUT_PATH bin/${CMAKE_BUILD_TYPE})

# Generation de la liste des fichiers sources
file(
        GLOB_RECURSE
        source_files
        src/*.cpp
)

# Declaration de l'executable
add_executable(
        ${EXECUTABLE_NAME}
        ${source_files}
)

# Detect and add SFML
set(CMAKE_MODULE_PATH "${CMAKE_SOURCE_DIR}/cmake_modules" ${CMAKE_MODULE_PATH})

#Find any version 1.6 of SFML
#See the FindSFML.cmake file for additional details and instructions
find_package(SFML 1.6 REQUIRED system window graphics)

if(SFML_FOUND)
  include_directories(${SFML_INCLUDE_DIR})
  target_link_libraries(${EXECUTABLE_NAME} ${SFML_LIBRARIES})
endif()

