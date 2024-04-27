/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpandipe <rpandipe.student.42luxembourg    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/27 16:23:44 by rpandipe          #+#    #+#             */
/*   Updated: 2024/04/27 17:59:41 by rpandipe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractal.h"

void	re_render(t_data *data)
{
	if (data->img_ptr)
		mlx_destroy_image(data->mlx_ptr, data->img_ptr);
	if (data->fractal == 1)
		mandelbrot(data);
	//else if (data->fractal == 2)
}

int	handle_key(int keysym, t_data *data)
{
	if (keysym == XK_Escape)
		destroy_mlx(data);
	else if (keysym == XK_Left)
		data->shift_x += (0.5 * data->zoom);
	else if (keysym == XK_Right)
		data->shift_x -= (0.5 * data->zoom);
	else if (keysym == XK_Down)
		data->shift_y += (0.5 * data->zoom);
	else if (keysym == XK_Up)
		data->shift_y -= (0.5 * data->zoom);
	else if (keysym == XK_KP_Add || keysym == XK_plus)
		data->c_switch += 1;
	else if (keysym == XK_KP_Subtract || keysym == XK_minus)
		data->c_switch -= 1;
	else
		return (0);
	re_render(data);
	return (0);
}

int	handle_mouse(int button, int x, int y, t_data *data)
{
	(void) x;
	(void) y;
	(void) data;
	//ft_printf("%d\n", button);
	if (button == Button4)
		data->zoom *= 0.95;
	else if (button == Button5)
		data->zoom *= 1.05;
	re_render(data);
	return (0);
}
