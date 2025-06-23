/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ckarsent <ckarsent@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/12 21:50:07 by ckarsent          #+#    #+#             */
/*   Updated: 2025/02/19 11:53:38 by ckarsent         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# include "../minilibx/mlx.h"
# include <stdlib.h>
# include <unistd.h>
# include <math.h>
# include <string.h>

# define L 400
# define H 400
# define MAX_ITER 50

typedef struct s_v
{
	void	*mlx;
	void	*win;
	void	*img;
	char	*addr;
	double	x_r;
	double	y_i;
	double	xx_r;
	double	yy_i;
	double	zoom;
	int		fractale;
	int		bpp;
	int		line_length;
	int		endian;
	int		i;
	int		j;
	int		color;
	int		iter;
	int		max_iter;
	double	x_r_bu;
	double	y_i_bu;
	double	z_r;
	double	z_i;
}	t_v;

/*calculs_and_color*/
int		mandelbrot(double x_r, double y_i, int max_iter);
int		julia(double z_r, double z_i, t_v *v);
int		color(int iterations);
int		rgb(int r, int g, int b);

/*draw*/
int		*init(t_v *v);
void	draw_pixels_mandelbrot(t_v *v, int *img_data);
void	draw_mandelbrot(t_v *v);
void	draw_pixels_julia(t_v *v, int *img_data);
void	draw_julia(t_v *v);

/*window*/
int		init_image(t_v *v);
int		init_window(t_v *v);
int		close_window(t_v *v);

/*mouse*/
void	zoom_plus(t_v *v);
void	zoom_moins(t_v *v);
int		key_mouse(int button, int x, int y, t_v *v);
int		key_handler(int keycode, t_v *v);

/*utils*/
int		ft_sign(char *str);
double	ft_atof(char *str);
int		ft_strcmp(char *s1, char *s2);
int		ft_isdigit(int c);

/*parsing*/
int		is_valid_double(char *s);
int		is_valid(int argc, char **argv);

/*main*/
int		print_error(void);
void	free_mlx(t_v *vars);
void	init_arguments(t_v *v, char **argv);
void	which_fractale(t_v *v, char *fractal);
int		main(int argc, char **argv);

#endif
