/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   julia.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpandipe <rpandipe.student.42luxembourg    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/29 15:29:11 by rpandipe          #+#    #+#             */
/*   Updated: 2024/04/30 15:10:01 by rpandipe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractal.h"

int	plot_julia(double a, double b, t_data *data)
{
	double	x;
	double	y;
	double	x2;
	double	y2;
	int		i;

	x = (scale(a, (double []){0, WINDOW_WIDTH - 1}, \
					data->min_x, data->max_x) * data->zoom) + data->shift_x;
	y = (scale(b, (double []){0, WINDOW_HEIGHT - 1}, \
					data->min_y, data->max_y) * data->zoom) + data->shift_y;
	a = data->julia_a;
	b = data->julia_b;
	x2 = x * x;
	y2 = y * y;
	i = 0;
	while (x2 + y2 <= 4 && i < MAX_ITERATIONS)
	{
		y = 2 * x * y + b;
		x = x2 - y2 + a;
		x2 = x * x;
		y2 = y * y;
		i++;
	}
	return (i);
}

void	julia(t_data *data)
{
	plot_image(data, &plot_julia);
	mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, data->img_ptr, 0, 0);
}
