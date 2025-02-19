/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calculs_and_color.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ckarsent <ckarsent@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/15 11:17:32 by ckarsent          #+#    #+#             */
/*   Updated: 2025/02/17 10:02:34 by ckarsent         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	mandelbrot(double x_r, double y_i, int max_iter)
{
	double	z_r;
	double	z_i;
	double	tmp;
	int		i;

	z_r = 0;
	z_i = 0;
	i = 0;
	while (z_r * z_r + z_i * z_i <= 4 && i < max_iter)
	{
		tmp = z_r * z_r - z_i * z_i + x_r;
		z_i = 2 * z_r * z_i + y_i;
		z_r = tmp;
		i++;
	}
	return (i);
}

int	julia(double z_r, double z_i, t_v *v)
{
	double	tmp;
	int		i;

	i = 0;
	while (z_r * z_r + z_i * z_i <= 4 && i < v->max_iter)
	{
		tmp = z_r * z_r - z_i * z_i + v->x_r;
		z_i = 2 * z_r * z_i + v->y_i;
		z_r = tmp;
		i++;
	}
	return (i);
}

int	color(int iterations)
{
	return (rgb(iterations * 20 % 256, iterations * 18 % 256,
			iterations * 105 % 256));
}

int	rgb(int r, int g, int b)
{
	return (r << 16 | g << 8 | b);
}
