/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpandipe <rpandipe.student.42luxembourg    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/25 09:21:15 by rpandipe          #+#    #+#             */
/*   Updated: 2024/04/29 18:29:36 by rpandipe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractal.h"

int	destroy_mlx(t_data *data)
{
	if (data->img_ptr)
		mlx_destroy_image(data->mlx_ptr, data->img_ptr);
	if (data->win_ptr && data->mlx_ptr)
		mlx_destroy_window(data->mlx_ptr, data->win_ptr);
	if (data->mlx_ptr)
	{
		mlx_loop_end(data->mlx_ptr);
		mlx_destroy_display(data->mlx_ptr);
		free(data->mlx_ptr);
	}
	exit(EXIT_SUCCESS);
}

void	events_init(t_data *data)
{
	mlx_hook(data->win_ptr, KeyPress, KeyPressMask, handle_key, data);
	mlx_hook(data->win_ptr, ButtonPress, ButtonPressMask, handle_mouse, data);
	mlx_hook(data->win_ptr, DestroyNotify, \
							StructureNotifyMask, destroy_mlx, data);
}

int	main(int argc, char **argv)
{
	t_data	data;

	if (argc == 2 && ft_strncmp(argv[1], "Mandelbrot", 10) == 0)
		init_mandelbrot(&data);
	else if ((argc == 4 && ft_strncmp(argv[1], "Julia", 5) == 0))
		init_julia(&data, argv);
	else if (argc == 2 && ft_strncmp(argv[1], "Burningship", 12) == 0)
		init_burning_ship(&data);
	else
	{
		ft_printf("Invalid Input.\nAvailable options: \n\t \
				Mandelbrot\n\t Julia <arg1> <arg2>\n\t Burningship\n");
		exit (1);
	}
	events_init(&data);
	mlx_loop(data.mlx_ptr);
	return (0);
}
