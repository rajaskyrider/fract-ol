/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   plot_pixel.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpandipe <rpandipe.student.42luxembourg    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/26 09:04:23 by rpandipe          #+#    #+#             */
/*   Updated: 2024/04/27 11:04:25 by rpandipe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractal.h"

unsigned int pretty_colors(int iter)
{
    double norm_i;
    double adj_i;
    int N;
    double S;

    N = 500;
    S = 2;
    norm_i = (double)iter / MAX_ITERATIONS;
    adj_i = pow(pow(norm_i, S) * N, 1.5);
    adj_i = fmod(adj_i, N);
    return (unsigned int)adj_i;
}

unsigned int		get_color(int iter)
{
	int	alpha;
	int	red;
	int	green;
	int	blue;

	alpha = 255;
	if (iter == MAX_ITERATIONS)
		return(0xFF000000);
	iter = pretty_colors(iter);
	red = iter * 128 % 	256;
	green = iter * 64 % 256;
	blue = iter * 192 % 256;
	return ((alpha << 24) | (red << 16) | (green << 8) | blue);
}

void	plot_image(t_data *data, int (*plot_func)(double, double))
{
	int	x;
	int	y;
	int	iter;
	unsigned int color;

	x = 0;
	data->img_ptr = mlx_new_image(data->mlx_ptr, WINDOW_WIDTH, WINDOW_HEIGHT);
	data->img_bfr = (int *)mlx_get_data_addr( \
					data->img_ptr, &data->bpp, &data->sizeline, &data->endian);
	while (x < WINDOW_WIDTH)
	{
		y = 0;
		while (y < WINDOW_HEIGHT)
		{
			iter = plot_func(x, y);
			color = get_color(iter);
			//color = (int)scale(iter, 0, 42, 0xFF000000, 0xFFFFFFFF);
			data->img_bfr[y * WINDOW_WIDTH + x] = color;
			y++;
		}
		x++;
	}
}
