/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpandipe <rpandipe.student.42luxembourg    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/25 10:39:20 by rpandipe          #+#    #+#             */
/*   Updated: 2024/04/29 18:36:46 by rpandipe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractal.h"

double	scale(double val, double fmin, double fmax, double tmin, double tmax)
{
	return (tmin + (val - fmin) * (tmax - tmin) / (fmax - fmin));
}

double	ft_atof(char *str, t_data *data)
{
	double	ans;
	double	d;
	int		sign;

	ans = 0;
	d = 1.0;
	sign = 1;
	if (*str == '-')
	{
		sign = -1;
		str++;
	}
	else if (*str == '+')
		str++;
	while (*str && *str >= '0' && *str <= '9')
	{
		ans = ans * 10 + (*str - '0');
		str++;
	}
	if (*str == '.')
	{
		++str;
		while (*str && *str >= '0' && *str <= '9')
		{
			d *= 10;
			ans = ans + ((*str - '0') / d);
			str++;
		}
	}
	if (*str != 0)
		destroy_mlx(data);
	return (sign * ans);
}
