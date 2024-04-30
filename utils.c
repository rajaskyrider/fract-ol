/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpandipe <rpandipe.student.42luxembourg    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/25 10:39:20 by rpandipe          #+#    #+#             */
/*   Updated: 2024/04/30 15:14:29 by rpandipe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractal.h"

double	scale(double val, double fm[2], double tmin, double tmax)
{
	return (tmin + (val - fm[0]) * (tmax - tmin) / (fm[1] - fm[0]));
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
