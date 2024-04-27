/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpandipe <rpandipe.student.42luxembourg    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/25 09:21:15 by rpandipe          #+#    #+#             */
/*   Updated: 2024/04/27 17:51:29 by rpandipe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractal.h"

void	initialize_mlx(t_data *data, char *name)
{
	data->mlx_ptr = mlx_init();
    if (!data->mlx_ptr)
        exit (1);
    data->win_ptr = mlx_new_window(data->mlx_ptr, WINDOW_WIDTH, WINDOW_HEIGHT, name);
    if (!data->win_ptr)
    {
        free(data->mlx_ptr);
        exit (1);
    }
	data->c_switch = 42;
	data->shift_x = 0;
	data->shift_y = 0;
	data->zoom = 1;
}

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
	mlx_hook(data->win_ptr, DestroyNotify, StructureNotifyMask, destroy_mlx, data);
}

int		main(int argc, char **argv)
{
	t_data	data;

	if (argc == 2 && ft_strncmp(argv[1], "Mandelbrot", 10) == 0)
	{
		initialize_mlx(&data, argv[1]);
		data.fractal = 1;
		mandelbrot(&data);
	}
	else if ((argc == 4 && ft_strncmp(argv[1], "Julia", 5) == 0))
	{
		initialize_mlx(&data, argv[1]);
	}
	else
	{
		ft_printf("Invalid Input. Available options: \n\t Mandelbrot \n\t Julia <arg1> <arg2>\n");
		exit (1);
	}
	events_init(&data);
	mlx_loop(data.mlx_ptr);
	return (0);
}

// %.o: %.c
	//$(CC) -Wall -Wextra -Werror -I/usr/include -Imlx_linux -O3 -c $< -o $@