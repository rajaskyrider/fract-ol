/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mandelbrot.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpandipe <rpandipe.student.42luxembourg    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/25 10:19:19 by rpandipe          #+#    #+#             */
/*   Updated: 2024/04/25 18:11:55 by rpandipe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractal.h"

int		plot_mandelbrot(double a, double b)
{
	double	x;
	double	y;
	double	x2;
	double	y2;
	int		i;

	x = 0.0;
	y = 0.0;
	x2 = 0.0;
	y2 = 0.0;
	i = 0;
	while (x2 + y2 <= 4 && i < MAX_ITERATIONS)
	{
		y = 2 * x * y + b;
		x = x2 + y2 + a;
		x2 = x * x;
		y2 = y * y;
		i++;
	}
	return (i);
}

void	mandelbrot(t_data *data)
{
	

	
	
}