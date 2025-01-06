/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: manelcarvalho <manelcarvalho@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/29 14:15:13 by manelcarval       #+#    #+#             */
/*   Updated: 2024/12/30 10:40:54 by manelcarval      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MLX42/MLX42.h" // Include the MLX42 header
#include <stdlib.h>      // For exit
#include <stdio.h>       // For printf

// // Callback function to terminate the program when the window is closed
// void close_program(mlx_t *mlx)
// {
//     printf("Exiting program.\n");
//     mlx_terminate(mlx); // Clean up and free MLX resources
//     exit(EXIT_SUCCESS);
// }

// int main(void)
// {
//     // Initialize MLX42 and create a window (800x600 resolution)
//     mlx_t *mlx = mlx_init(800, 600, "MLX42 Window", true);
//     if (!mlx)
//     {
//         fprintf(stderr, "MLX initialization failed\n");
//         return EXIT_FAILURE;
//     }

//     // Hook a function to close the program on window close
//     mlx_close_hook(mlx, (void *)close_program, mlx);

//     // Start the MLX42 main loop (keeps the window open)
//     mlx_loop(mlx);

//     // Terminate MLX42 (this won't be reached unless the loop breaks)
//     mlx_terminate(mlx);
//     return EXIT_SUCCESS;
// }

#include "MLX42/MLX42.h"
#include <stdio.h>
#include <stdlib.h>

#define WIDTH 800
#define HEIGHT 600

void close_window(mlx_t *mlx)
{
    mlx_terminate(mlx);
    exit(0);
}

int main(void)
{
    // Initialize MLX42
    mlx_t *mlx = mlx_init(WIDTH, HEIGHT, "Fract-ol", true);
    if (!mlx)
    {
        fprintf(stderr, "Failed to initialize MLX42\n");
        return EXIT_FAILURE;
    }

    // Set up the close event
    mlx_close_hook(mlx, (void (*)(void *))close_window, mlx);

    // Render Loop
    mlx_loop(mlx);

    // Clean up
    mlx_terminate(mlx);
    return 0;
}
