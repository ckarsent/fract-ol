/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouse_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ckarsent <ckarsent@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/17 14:04:38 by ckarsent          #+#    #+#             */
/*   Updated: 2025/02/17 14:09:42 by ckarsent         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol_bonus.h"

void	zoom_plus(t_v *v)
{
	v->zoom *= 1.1;
	if (v->max_iter < 1000)
		v->max_iter += 2;
}

void	zoom_moins(t_v *v)
{
	v->zoom /= 1.1;
	if (v->max_iter > 50)
		v->max_iter -= 2;
}

int	key_mouse(int button, int x, int y, t_v *v)
{
	(void)x;
	(void)y;
	if (button == 4)
		zoom_plus(v);
	else if (button == 5)
		zoom_moins(v);
	if (v->fractale == 0)
		draw_mandelbrot(v);
	else if (v->fractale == 1)
		draw_julia(v);
	else if (v->fractale == 2)
		draw_burningship(v);
	return (0);
}

int	key_handler(int keycode, t_v *v)
{
	if (keycode == 65307)
	{
		free_mlx(v);
		exit(0);
	}
	if (keycode == 61)
		zoom_plus(v);
	else if (keycode == 45)
		zoom_moins(v);
	else if (keycode == 65362)
		v->yy_i -= 0.1 / v->zoom;
	else if (keycode == 65364)
		v->yy_i += 0.1 / v->zoom;
	else if (keycode == 65361)
		v->xx_r -= 0.1 / v->zoom;
	else if (keycode == 65363)
		v->xx_r += 0.1 / v->zoom;
	if (v->fractale == 0)
		draw_mandelbrot(v);
	else if (v->fractale == 1)
		draw_julia(v);
	else if (v->fractale == 2)
		draw_burningship(v);
	return (0);
}
