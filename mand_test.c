/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mand_test.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpandipe <rpandipe.student.42luxembourg    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/27 09:38:53 by rpandipe          #+#    #+#             */
/*   Updated: 2024/04/29 15:12:48 by rpandipe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
/*#include <math.h>

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
    S = 4;
    norm_i = (double)iter / MAX_ITERATIONS;
    adj_i = pow(pow(norm_i, S) * N, 1.5);
    adj_i = fmod(adj_i, N);
    return (unsigned int)adj_i;
}

unsigned int get_color(int iter)
{
    int alpha;
    int red;
    int green;
    int blue;
    double norm;

    alpha = 255;
    if (iter == MAX_ITERATIONS)
        return (0xFF000000);

    // Calculate normalized value
    norm = (double)iter / MAX_ITERATIONS;

    int initialRed;
    int initialGreen;
    int initialBlue;

    // Generate shades of purple and yellow
    if (iter % 2 == 0) {
        // Even iterations: shades of purple
        initialRed = 128 + (int)(norm * 127);
        initialGreen = 0;
        initialBlue = 128 + (int)(norm * 127);
    } else {
        // Odd iterations: shades of yellow
        initialRed = 255;
        initialGreen = 255 - (int)(norm * 127);
        initialBlue = 0;
    }

    // Modify shade based on iteration
    red = (int)(initialRed % 256);
    green = (int)(initialGreen % 256);
    blue = (int)(initialBlue % 256);

    // Clamp values to ensure they are within valid range
    if (red < 50) red = 50;
    if (green < 50) green = 50;
    if (blue < 50) blue = 50;
    if (red > 200) red = 200;
    if (green > 200) green = 200;
    if (blue > 200) blue = 200;

    return ((alpha << 24) | (red << 16) | (green << 8) | blue);
}

void	color()
{
	int	iter;
	unsigned int color;

	iter = 0;
	while (iter <= 500)
	{
		//color = pretty_colors(iter);
		color = (unsigned int)scale(pretty_colors(iter), 0, 500, 0xFF010000, 0xFFEFEFEF);
		printf("Color %X\n", color);
		iter++;
	}
}*/

int main(void)
{
    char *f = "1.414";
    double  ans;
    float     d;

    ans = 0;
    d = 1;
    while (*f && *f != '.')
    {
        ans = ans * 10 + (*f - '0');
        f++;
    }
    if (*f == '.')
    {
        ++f;
        while (*f)
        {
            d *= 10;
            ans = ans + ((*f - '0') / d);
            f++;
        }
    }
    printf("ans :%f", ans);
}