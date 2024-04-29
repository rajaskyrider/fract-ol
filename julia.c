/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   julia.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpandipe <rpandipe.student.42luxembourg    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/29 15:29:11 by rpandipe          #+#    #+#             */
/*   Updated: 2024/04/29 16:30:43 by rpandipe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractal.h"

int		plot_julia(double a, double b, t_data *data)
{
	double	x;
	double	y;
	double	x2;
	double	y2;
	int		i;

	x = (scale(a, 0, WINDOW_WIDTH - 1, 2, -2) * data->zoom) + data->shift_x;
	y = (scale(b, 0, WINDOW_HEIGHT - 1, -2, 2) * data->zoom) + data->shift_y;
	a = data->julia_a;
	b = data->julia_b;
	//ft_printf("a :%d \t b :%d\n", a, b);
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