cmake_minimum_required(VERSION 3.16)
project(fractol C)

set(CMAKE_C_STANDARD 99)

# Include MLX42
add_subdirectory(lib/MLX42)
include_directories(lib/MLX42/include)
include_directories(include)

# Add your source files
add_executable(fractol
    #src/main.c
    src/fractol.c
    #src/render.c
)

# Link MLX42
target_link_libraries(fractol PRIVATE MLX42 glfw)
