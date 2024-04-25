/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractal.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpandipe <rpandipe.student.42luxembourg    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/25 09:21:29 by rpandipe          #+#    #+#             */
/*   Updated: 2024/04/25 18:06:04 by rpandipe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTAL_H
# define FRACTAL_H

# include <stdlib.h>
# include <unistd.h>
# include "./libft/libft.h"
# include "./mlx_linux/mlx.h"

# define WINDOW_WIDTH 800
# define WINDOW_HEIGHT 800
# define MAX_ITERATIONS 500

typedef struct	s_data
{
    void	*mlx_ptr;
    void	*win_ptr;
}				t_data;

typedef	struct	s_fractal
{
	double	x;
	double	y;		
}				t_fractal;

void	mandelbrot(t_data *data);
double	scale(double val, double fmin, double fmax, double tmin, double tmax);

#endif