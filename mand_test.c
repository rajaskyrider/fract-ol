/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mand_test.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpandipe <rpandipe.student.42luxembourg    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/27 09:38:53 by rpandipe          #+#    #+#             */
/*   Updated: 2024/04/27 11:11:14 by rpandipe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <math.h>

# define MAX_ITERATIONS 500

double	scale(double val, double fmin, double fmax, double tmin, double tmax)
{
    return (tmin + (val - fmin) * (tmax - tmin) / (fmax - fmin));
}

void	mandel()
{
	double	a;
	double	b;
	double	x;
	double	y;
	double	x2;
	double	y2;
	int		i;

	a = 5;
	b = 2;
	//a = scale(a, 0, 800, -2, 2);
	//b = scale(b, 0, 800, -2, 2);
	x = 0;
	y = 0;
	x2 = 0.0;
	y2 = 0.0;
	i = 0;
	while (i < 10)
	{
		y = 2 * x * y + b;
		x = x2 - y2 + a;
		printf("x = %f\t", x);
		printf("y = %f\n", y);
		x2 = x * x;
		y2 = y * y;
		i++;
	}
}
void scale_test(void)
{
	int i;

	i = 0;
	while (i < 800)
	{
		printf("val %d /t Scale %f\n", i, scale(i, 0, 799, -2, 2));
		i++;
	}
}

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
	//iter = pretty_colors(iter);
	red = iter % 256;
	green = 0;
	blue = 0;
	return ((alpha << 24) | (red << 16) | (green << 8) | blue);
}

int	main()
{
	int	iter;

	iter = 0;
	while (iter < 500)
	{
		printf("Color %X\n", get_color(iter));
		iter++;
	}
}