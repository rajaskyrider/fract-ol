/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpandipe <rpandipe.student.42luxembourg    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/29 17:11:57 by rpandipe          #+#    #+#             */
/*   Updated: 2024/05/01 10:40:32 by rpandipe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractal.h"

void	initialize_mlx(t_data *data, char *name)
{
	data->mlx_ptr = mlx_init();
	if (!data->mlx_ptr)
		exit (EXIT_FAILURE);
	data->win_ptr = mlx_new_window(data->mlx_ptr, \
						WINDOW_WIDTH, WINDOW_HEIGHT, name);
	if (!data->win_ptr)
	{
		free(data->mlx_ptr);
		exit (EXIT_FAILURE);
	}
	data->img_ptr = NULL;
	data->c_switch = 42;
	data->shift_x = 0;
	data->shift_y = 0;
	data->zoom = 1;
}

void	init_mandelbrot(t_data *data)
{
	initialize_mlx(data, "Mandelbrot");
	data->fractal = 1;
	data->min_x = -2;
	data->max_x = 2;
	data->min_y = 2;
	data->max_y = -2;
	data->rx = 1;
	data->ry = 1;
	mandelbrot(data);
}

void	init_julia(t_data *data, char **argv)
{
	initialize_mlx(data, argv[1]);
	data->julia_a = ft_atof(argv[2], data);
	data->julia_b = ft_atof(argv[3], data);
	data->fractal = 2;
	data->min_x = 2;
	data->max_x = -2;
	data->min_y = -2;
	data->max_y = 2;
	data->rx = -1;
	data->ry = -1;
	julia(data);
}

void	init_burning_ship(t_data *data)
{
	initialize_mlx(data, "Burning Ship");
	data->fractal = 3;
	data->min_x = -2;
	data->max_x = 2;
	data->min_y = -2;
	data->max_y = 2;
	data->rx = 1;
	data->ry = -1;
	burning_ship(data);
}
