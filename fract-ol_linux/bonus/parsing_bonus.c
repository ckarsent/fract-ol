/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ckarsent <ckarsent@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/14 08:37:59 by ckarsent          #+#    #+#             */
/*   Updated: 2025/02/16 12:50:05 by ckarsent         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol_bonus.h"

int	is_valid_double(char *s)
{
	int	i;
	int	nb;
	int	dot;

	i = 0;
	nb = 0;
	dot = 0;
	if (s[i] == '-' || s[i] == '+')
		i++;
	while (s[i])
	{
		if (ft_isdigit(s[i]))
			nb = 1;
		else if (s[i] == '.')
		{
			if (dot)
				return (0);
			dot = 1;
		}
		else
			return (0);
		i++;
	}
	return (nb);
}

int	is_valid(int argc, char **argv)
{
	if (argc == 1)
		return (0);
	if (!ft_strcmp(argv[1], "julia") || !ft_strcmp(argv[1], "mandelbrot")
		|| !ft_strcmp(argv[1], "burningship"))
	{
		if (argv[1][0] == 'm' && argc == 2)
			return (1);
		else if (argv[1][0] == 'b' && argc == 2)
			return (1);
		else if (argv[1][0] == 'j' && argc == 4 &&
			is_valid_double(argv[2]) && is_valid_double(argv[3]))
			return (1);
	}
	return (0);
}
