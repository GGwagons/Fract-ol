/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checks.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miturk <miturk@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/28 15:02:26 by miturk            #+#    #+#             */
/*   Updated: 2023/12/29 16:45:44 by miturk           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fract_ol.h"

void	ft_num_check1(t_ps *d_list, char **argv)
{
	d_list->i = 0;
	while (argv[2][d_list->i] != '\0')
	{
		if ((argv[2][d_list->i] == '-' || argv[2][d_list->i] == '+')
			&& argv[2][d_list->i + 1] == '\0')
		{
			ft_putendl_fd("Incorrect input", 2);
			free(d_list);
			exit (1);
		}
		else if (argv[2][d_list->i] == '.' || (argv[2][d_list->i] >= '0'
			&& argv[2][d_list->i] <= '9'))
			d_list->i++;
		else if (argv[2][d_list->i] == '-' || argv[2][d_list->i] == '+')
			d_list->i++;
		else
		{
			ft_putendl_fd("Incorrect input", 2);
			free(d_list);
			exit (1);
		}
	}
}

void	ft_num_check2(t_ps *d_list, char **argv)
{
	d_list->i = 0;
	while (argv[3][d_list->i] != '\0')
	{
		if ((argv[3][d_list->i] == '-' || argv[3][d_list->i] == '+')
			&& argv[3][d_list->i + 1] == '\0')
		{
			ft_putendl_fd("Incorrect input", 2);
			free(d_list);
			exit (1);
		}
		if (argv[3][d_list->i] == '-' || argv[3][d_list->i] == '+')
			d_list->i++;
		else if (argv[3][d_list->i] == '.' || (argv[3][d_list->i] >= '0'
			&& argv[3][d_list->i] <= '9'))
			d_list->i++;
		else
		{
			ft_putendl_fd("Incorrect input", 2);
			free(d_list);
			exit (1);
		}
	}
}

int	ft_check_args(char **argv, t_ps *d_list)
{
	if (ft_strcmp(argv[1], "Mandelbrot") == 0)
	{
		if (argv[2] == NULL || argv[3] == NULL)
			set_mandelbrot_fractol(d_list);
		else
		{
			ft_putendl_fd("Incorrect fractol", 2);
			ft_putendl_fd("Available fractol: Mandelbrot <No paramaters>\n", 2);
			ft_putendl_fd("\t\t   Julia <no paramaters/two paramaters>\n", 2);
			free(d_list);
			exit (1);
		}
	}
	else if (ft_strcmp(argv[1], "Julia") == 0)
		set_julia_fractol(d_list, argv);
	else
	{
		ft_putendl_fd("Incorrect fractol", 2);
		ft_putendl_fd("Available fractol: Mandelbrot <No paramaters>\n", 2);
		ft_putendl_fd("\t\t   Julia <no paramaters/two paramaters>\n", 2);
		free(d_list);
		exit (1);
	}
	return (0);
}

static double	ft_deci(const char *s)
{
	double		res1;
	double		res2;
	int			i;
	int			j;

	res1 = 0.0;
	res2 = 0.0;
	i = 0;
	j = 0;
	while (*s >= '0' && *s <= '9')
		res1 = res1 * 10.0 + (*s++ - '0');
	if (*s++ == '.')
	{
		while (*s >= '0' && *s <= '9')
		{
			res2 = res2 * 10.0 + (*s++ - '0');
			i++;
		}
	}
	while (j++ < i)
		res2 = res2 / 10.0;
	return (res1 + res2);
}

double	ft_atof(const char *s)
{
	int			sign;
	double		result;

	result = 0.0;
	sign = 1;
	if (*s == '-' || *s == '+')
	{
		if (*s == '-')
			sign = -1;
		s++;
	}
	result = ft_deci(s);
	return (result * sign);
}
