/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   burning_ship.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpandipe <rpandipe.student.42luxembourg    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/29 16:55:32 by rpandipe          #+#    #+#             */
/*   Updated: 2024/04/30 15:08:51 by rpandipe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractal.h"

int	plot_burning_ship(double a, double b, t_data *data)
{
	double	x;
	double	y;
	double	x2;
	double	y2;
	int		i;

	a = (scale(a, (double []){0, WINDOW_WIDTH - 1}, \
				data->min_x, data->max_x) * data->zoom) + data->shift_x;
	b = (scale(b, (double []){0, WINDOW_HEIGHT - 1}, \
				data->min_y, data->max_y) * data->zoom) + data->shift_y;
	x = 0.0;
	y = 0.0;
	x2 = 0.0;
	y2 = 0.0;
	i = 0;
	while (x2 + y2 <= 4 && i < MAX_ITERATIONS)
	{
		y = fabs(2 * x * y) + b;
		x = fabs(x2 - y2 + a);
		x2 = x * x;
		y2 = y * y;
		i++;
	}
	return (i);
}

void	burning_ship(t_data *data)
{
	plot_image(data, &plot_burning_ship);
	mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, data->img_ptr, 0, 0);
}
