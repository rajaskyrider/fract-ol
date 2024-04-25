/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpandipe <rpandipe.student.42luxembourg    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/25 18:29:42 by rpandipe          #+#    #+#             */
/*   Updated: 2024/04/25 18:43:18 by rpandipe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mlx_linux/mlx.h"
#include <stdlib.h>
#include <stdio.h>
#include <math.h>

#define WIDTH 800
#define HEIGHT 800
#define MAX_ITERATIONS 1000
#define PALETTE_SIZE 256

// Structure to hold image data
typedef struct s_image {
    void *mlx;
    void *win;
    void *image;
    char *data;
    int bpp;
    int sizeline;
    int endian;
} t_image;

// Structure to hold 3D fractal data
typedef struct s_3d {
    t_image img; // Image data
} t_3d;

// Function prototypes
void init_img(t_3d *d);
void put_pixel_in_img(t_3d *d, int x, int y, int color);
void fractol(t_3d *d);
void draw_fractal(t_3d *d);

// Example fractal drawing function
void draw_fractal(t_3d *d) {
    // Your fractal drawing code here
    // Example: drawing Mandelbrot set
    // Iterate over each pixel and set its color
    for (int y = 0; y < HEIGHT; y++) {
        for (int x = 0; x < WIDTH; x++) {
            // Placeholder or your actual color calculation code
            int color = 0; // Replace with your code
            put_pixel_in_img(d, x, y, color); // Put pixel in image
        }
    }
}

// Function to initialize image
void init_img(t_3d *d) {
    d->img.image = mlx_new_image(d->img.mlx, WIDTH, HEIGHT);
    d->img.data = mlx_get_data_addr(d->img.image, &d->img.bpp, &d->img.sizeline, &d->img.endian);
}

// Function to put pixel in image
void put_pixel_in_img(t_3d *d, int x, int y, int color) {
    if (x >= 0 && y >= 0 && x < WIDTH && y < HEIGHT) {
        int index = (y * d->img.sizeline) + (x * (d->img.bpp / 8));
        *(unsigned int *)(d->img.data + index) = color;
    }
}

// Function to display fractal
void fractol(t_3d *d) {
    init_img(d); // Initialize image
    draw_fractal(d); // Draw fractal onto image
    mlx_put_image_to_window(d->img.mlx, d->img.win, d->img.image, 0, 0); // Put image on window
}

int main(void) {
    t_3d d;
    // Initialize MiniLibX and create window
    d.img.mlx = mlx_init();
    d.img.win = mlx_new_window(d.img.mlx, WIDTH, HEIGHT, "Fractal Window");
    // Display fractal
    fractol(&d);
    mlx_loop(d.img.mlx);
    return 0;
}
