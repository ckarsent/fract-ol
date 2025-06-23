/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ckarsent <ckarsent@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/14 09:39:54 by ckarsent          #+#    #+#             */
/*   Updated: 2025/02/16 12:28:18 by ckarsent         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	ft_sign(char *str)
{
	if (str[0] == '-' || str[0] == '+')
	{
		if (str[0] == '-')
			return (-1);
	}
	return (1);
}

double	ft_atof(char *str)
{
	int		i;
	int		sign;
	double	res;
	double	factor;

	i = 0;
	sign = ft_sign(str);
	res = 0.0;
	factor = 1.0;
	if (str[i] == '+' || str[i] == '-')
		i++;
	while (str[i] && (str[i]) >= '0' && str[i] <= '9')
		res = res * 10 + (str[i++] - '0');
	if (str[i] == '.')
	{
		while (str[++i] && (str[i] >= '0' && str[i] <= '9'))
		{
			factor = factor / 10.0;
			res = res + ((str[i] - '0') * factor);
		}
	}
	if (str[i] != '\0')
		return (0);
	return (res * sign);
}

int	ft_strcmp(char *s1, char *s2)
{
	int	i;

	i = 0;
	while (s1[i] || s2[i])
	{
		if (s1[i] != s2[i])
			return (s1[i] - s2[i]);
		i++;
	}
	return (0);
}

int	ft_isdigit(int c)
{
	if (c < '0' || c > '9')
		return (0);
	return (1);
}
