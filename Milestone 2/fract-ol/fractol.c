/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: manelcarvalho <manelcarvalho@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/29 14:07:54 by manelcarval       #+#    #+#             */
/*   Updated: 2024/12/30 12:21:25 by manelcarval      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MLX42/MLX42.h"
#include <stdlib.h>
#include <stdio.h>

void close_program(mlx_t *mlx)
{
    mlx_terminate(mlx);
    exit(EXIT_SUCCESS);
}
int main(void)
{
    mlx_t *mlx = mlx_init(800, 600, "Fract-ol", true);
    if (!mlx)
    {
        fprintf(stderr, "MLX initialization failed\n");
        return EXIT_FAILURE;
    }

    mlx_loop_hook(mlx, (void *)close_program, mlx);
    mlx_loop(mlx);
    mlx_terminate(mlx);
    return EXIT_SUCCESS;
}
