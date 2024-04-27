/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractal.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpandipe <rpandipe.student.42luxembourg    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/25 09:21:29 by rpandipe          #+#    #+#             */
/*   Updated: 2024/04/26 10:59:33 by rpandipe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTAL_H
# define FRACTAL_H

# include <stdlib.h>
# include <unistd.h>
# include <math.h>
# include "./libft/libft.h"
# include "./mlx_linux/mlx.h"

# define WINDOW_WIDTH 800
# define WINDOW_HEIGHT 800
# define MAX_ITERATIONS 500

typedef struct	s_data
{
    void	*mlx_ptr;
    void	*win_ptr;
	void	*img_ptr;
	int		*img_bfr;
	int		bpp;
    int		sizeline;
    int		endian;
}				t_data;

typedef	struct	s_color
{
	unsigned char	r;
	unsigned char	g;
	unsigned char	b;
	unsigned char	a;
}				t_color;

void	mandelbrot(t_data *data);
double	scale(double val, double fmin, double fmax, double tmin, double tmax);
void	plot_image(t_data *data, int (*plot_func)(double, double));

#endif