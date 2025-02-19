/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_burningship_bonus.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ckarsent <ckarsent@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/16 18:12:29 by ckarsent          #+#    #+#             */
/*   Updated: 2025/02/17 09:58:22 by ckarsent         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol_bonus.h"

void	draw_pixels_burningship(t_v *v, int *img_data)
{
	int	couleur;

	v->j = 0;
	while (v->j < H)
	{
		v->i = 0;
		while (v->i < L)
		{
			v->x_r_bu = (v->i - L / 2.0) * 4.0 / (L * v->zoom) + v->xx_r;
			v->y_i_bu = (v->j - H / 2.0) * 4.0 / (H * v->zoom) + v->yy_i;
			v->iter = burningship(v->x_r_bu, v->y_i_bu, v->max_iter);
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

void	draw_burningship(t_v *v)
{
	int	*img_data;

	img_data = init(v);
	if (!img_data)
		return ;
	draw_pixels_burningship(v, img_data);
	mlx_put_image_to_window(v->mlx, v->win, v->img, 0, 0);
}
