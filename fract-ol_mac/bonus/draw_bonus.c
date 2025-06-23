/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ckarsent <ckarsent@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/15 11:34:36 by ckarsent          #+#    #+#             */
/*   Updated: 2025/02/17 10:01:30 by ckarsent         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol_bonus.h"

int	*init(t_v *v)
{
	if (v->img)
		mlx_destroy_image(v->mlx, v->img);
	v->img = mlx_new_image(v->mlx, L, H);
	if (!v->img)
		return (NULL);
	return ((int *)mlx_get_data_addr(v->img, &v->bpp,
			&v->line_length, &v->endian));
}

void	draw_pixels_mandelbrot(t_v *v, int *img_data)
{
	int	couleur;

	v->j = 0;
	while (v->j < H)
	{
		v->i = 0;
		while (v->i < L)
		{
			v->x_r = (v->i - L / 2.0) * 4.0 / (L * v->zoom) + v->xx_r;
			v->y_i = (v->j - H / 2.0) * 4.0 / (H * v->zoom) + v->yy_i;
			v->iter = mandelbrot(v->x_r, v->y_i, v->max_iter);
			if (v->iter == v->max_iter)
				couleur = rgb(0, 0, 0);
			else
				couleur = color(v->iter);
			img_data[v->j * L + v->i] = couleur;
			v->i++;
		}
		v->j++;
	}
}

void	draw_mandelbrot(t_v *v)
{
	int	*img_data;

	img_data = init(v);
	if (!img_data)
		return ;
	draw_pixels_mandelbrot(v, img_data);
	mlx_put_image_to_window(v->mlx, v->win, v->img, 0, 0);
}

void	draw_pixels_julia(t_v *v, int *img_data)
{
	int	couleur;

	v->j = 0;
	while (v->j < H)
	{
		v->i = 0;
		while (v->i < L)
		{
			v->z_r = (v->i - L / 2.0) * 4.0 / (L * v->zoom) + v->xx_r;
			v->z_i = (v->j - H / 2.0) * 4.0 / (H * v->zoom) + v->yy_i;
			v->iter = julia(v->z_r, v->z_i, v);
			if (v->iter == v->max_iter)
				couleur = rgb(0, 0, 0);
			else
				couleur = color(v->iter);
			img_data[v->j * L + v->i] = couleur;
			v->i++;
		}
		v->j++;
	}
}

void	draw_julia(t_v *v)
{
	int	*img_data;

	img_data = init(v);
	if (!img_data)
		return ;
	draw_pixels_julia(v, img_data);
	mlx_put_image_to_window(v->mlx, v->win, v->img, 0, 0);
}
