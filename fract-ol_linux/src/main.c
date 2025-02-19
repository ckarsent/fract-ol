/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ckarsent <ckarsent@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/12 21:49:33 by ckarsent          #+#    #+#             */
/*   Updated: 2025/02/17 14:20:08 by ckarsent         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	print_error(void)
{
	write(2, "Usage: ./fractol [mandelbrot|julia] [options]\n", 47);
	write(2, "\nOptions:\n", 10);
	write(2, "  mandelbrot      : Dessine la fractale de Mandelbrot.\n", 56);
	write(2, "  julia [re] [im] : Dessine la fractale de Julia avec la ", 57);
	write(2, "partie réelle 're' et la partie imaginaire 'im'.\n", 50);
	write(2, "\nExemples:\n", 11);
	write(2, "  ./fractol mandelbrot\n", 23);
	write(2, "  ./fractol julia -0.8 0.156\n", 30);
	return (0);
}

void	free_mlx(t_v *vars)
{
	if (vars->win)
		mlx_destroy_window(vars->mlx, vars->win);
	if (vars->img)
		mlx_destroy_image(vars->mlx, vars->img);
	if (vars->mlx)
		mlx_destroy_display(vars->mlx);
	free(vars->mlx);
}

void	init_arguments(t_v *v, char **argv)
{
	if (!ft_strcmp(argv[1], "julia"))
	{
		v->x_r = ft_atof(argv[2]);
		v->y_i = ft_atof(argv[3]);
	}
	v->xx_r = 0.0;
	v->yy_i = 0.0;
	v->zoom = 1.0;
}

void	which_fractale(t_v *v, char *fractal)
{
	if (!ft_strcmp(fractal, "mandelbrot"))
	{
		v->fractale = 0;
		draw_mandelbrot(v);
	}
	else if (!ft_strcmp(fractal, "julia"))
	{
		v->fractale = 1;
		draw_julia(v);
	}
}

int	main(int argc, char **argv)
{
	t_v	v;

	if (!is_valid(argc, argv))
		return (print_error());
	init_arguments(&v, argv);
	if (!init_window(&v))
		return (1);
	if (!init_image(&v))
		return (1);
	v.max_iter = 100;
	which_fractale(&v, argv[1]);
	mlx_hook(v.win, 2, 1L << 0, key_handler, &v);
	mlx_mouse_hook(v.win, key_mouse, &v);
	mlx_hook(v.win, 17, 0, close_window, &v);
	mlx_loop(v.mlx);
	return (0);
}
