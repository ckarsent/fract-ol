/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ckarsent <ckarsent@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/15 10:37:41 by ckarsent          #+#    #+#             */
/*   Updated: 2025/02/17 15:19:32 by ckarsent         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	init_image(t_v *v)
{
	v->img = mlx_new_image(v->mlx, L, H);
	if (!v->img)
		return (0);
	v->addr = mlx_get_data_addr(v->img, &v->bpp,
			&v->line_length, &v->endian);
	return (1);
}

int	init_window(t_v *v)
{
	v->mlx = mlx_init();
	if (!v->mlx)
		return (0);
	v->win = mlx_new_window(v->mlx, L, H, "Fractol");
	if (!v->win)
		return (0);
	return (1);
}

int	close_window(t_v *v)
{
	free_mlx(v);
	exit(0);
	return (0);
}
