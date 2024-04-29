/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   plot_pixel.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpandipe <rpandipe.student.42luxembourg    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/26 09:04:23 by rpandipe          #+#    #+#             */
/*   Updated: 2024/04/29 18:31:36 by rpandipe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractal.h"

unsigned int	get_color(int iter, t_data *data)
{
	(void)data;
	if (iter == MAX_ITERATIONS)
		return (0xFF000000);
	return ((unsigned int)scale(iter, 0, \
			data->c_switch, 0xFFEEEEEE, 0xFF010000));
}

void	plot_image(t_data *data, int (*plot_func)(double, double, t_data *))
{
	int				x;
	int				y;
	int				iter;
	unsigned int	color;

	x = 0;
	data->img_ptr = mlx_new_image(data->mlx_ptr, WINDOW_WIDTH, WINDOW_HEIGHT);
	data->img_bfr = (int *)mlx_get_data_addr(\
					data->img_ptr, &data->bpp, &data->sizeline, &data->endian);
	while (x < WINDOW_WIDTH)
	{
		y = 0;
		while (y < WINDOW_HEIGHT)
		{
			iter = plot_func(x, y, data);
			color = get_color(iter, data);
			data->img_bfr[y * WINDOW_WIDTH + x] = color;
			y++;
		}
		x++;
	}
}
