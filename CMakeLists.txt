cmake_minimum_required(VERSION 2.6)

# Declaration du projet
project(mandelbrot)

# Path de l'executable
set(EXECUTABLE_OUTPUT_PATH bin/${CMAKE_BUILD_TYPE})

# Includes Path
include_directories(${SFML_DIR}/include)

# Link directory
link_directories(${SFML_DIR}/lib)

# Generation de la liste des fichiers sources
file(
        GLOB_RECURSE
        source_files
        src/*.cpp
)

# Declaration de l'executable
add_executable(
        mandelbrot
        ${source_files}
)

# link definition
target_link_libraries(
        mandelbrot
        sfml-graphics
        sfml-window
        sfml-system
)
