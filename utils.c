/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpandipe <rpandipe.student.42luxembourg    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/25 10:39:20 by rpandipe          #+#    #+#             */
/*   Updated: 2024/04/25 10:46:05 by rpandipe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractal.h"

double	scale(double val, double fmin, double fmax, double tmin, double tmax)
{
    return (tmin + (val - fmin) * (tmax - tmin) / (fmax - fmin));
}