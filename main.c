/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpandipe <rpandipe.student.42luxembourg    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/25 09:21:15 by rpandipe          #+#    #+#             */
/*   Updated: 2024/04/26 11:32:29 by rpandipe         ###   ########.fr       */
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
}

void	destroy_mlx(t_data *data)
{
	mlx_destroy_display(data->mlx_ptr);
    free(data->mlx_ptr);
}

int		main(int argc, char **argv)
{
	t_data	data;

	if (argc == 2 && ft_strncmp(argv[1], "Mandelbrot", 10) == 0)
	{
		initialize_mlx(&data, argv[1]);
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
	mlx_loop(data.mlx_ptr);
	destroy_mlx(&data);
	return (0);
}

// %.o: %.c
	//$(CC) -Wall -Wextra -Werror -I/usr/include -Imlx_linux -O3 -c $< -o $@