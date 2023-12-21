/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Julia.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miturk <miturk@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/15 13:41:00 by miturk            #+#    #+#             */
/*   Updated: 2023/12/21 15:52:28 by miturk           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fract_ol.h"

void	set_julia_fractol(t_ps *d_list, char **argv)
{
	d_list->name = JULIA;
	d_list->x = 0;
	d_list->y = 0;
	d_list->x_off = 0.0;
	d_list->y_off = 0.0;
	d_list->zoom = 1;
	d_list->color = 0x250697;
	d_list->endian = 0;
	d_list->line_length = 0;
	d_list->max_iter = 100;
	d_list->z_real = 0.0;
	d_list->z_img = 0.0;
	d_list->arrow_x = 0;
	d_list->arrow_y = 0;
	if (argv[2] && argv[3])
	{
		d_list->c_real = ft_custom_args(&argv[2]);
		d_list->c_img = ft_custom_args(&argv[3]);
	}
	else if (!argv[2] || !argv[3])
	{
		d_list->c_real = -0.8696;
		d_list->c_img = 0.26;
	}
}

void	ft_julia(t_ps *d_list)
{
	int	i;

	i = 0;
	d_list->x = 0;
	d_list->y = 0;
	while (d_list->y++ <= HEIGHT)
	{
		while (d_list->x++ <= WIDTH)
		{
			i = ft_is_julia(d_list);
			ft_color(d_list, i);
		}
		d_list->x = 0;
	}
	mlx_put_image_to_window(d_list->mlx, d_list->win, d_list->img, 0, 0);
}

int	ft_is_julia(t_ps *d_list)
{
	int	i;
	double temp;
	
	i = 0;
	d_list->z_real = 1.9 * (d_list->x - WIDTH / 2) / (0.5 * d_list->zoom * WIDTH) + d_list->x_off;
	d_list->z_img = 1.5 * (d_list->y - HEIGHT / 2) / (0.5 * d_list->zoom * HEIGHT) + d_list->y_off;
	d_list->re_new = d_list->z_real;
	d_list->img_new = d_list->z_img;
	while (i++ < d_list->max_iter)
	{
		if ((d_list->re_new * d_list->re_new
			+ d_list->img_new * d_list->img_new) > 4.0)
			break ;
		temp = 2 * d_list->re_new * d_list->img_new + d_list->c_img;
		d_list->re_new = d_list->re_new * d_list->re_new - d_list->img_new * d_list->img_new + d_list->c_real;
		d_list->img_new = temp;
	}
	return (i);
}