/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mandelbrot.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miturk <miturk@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/18 11:08:40 by miturk            #+#    #+#             */
/*   Updated: 2023/12/19 17:35:43 by miturk           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fract_ol.h"

void	ft_mandelbrot(t_ps	*d_list)
{
	int	i;

	d_list->x = 0;
	d_list->y = 0;
	while (d_list->y++ <= HEIGHT)
	{
		while (d_list->x++ <= WIDTH)
		{
			ft_cal_mandelbrot(d_list);
			d_list->img_old = 0;
			d_list->re_old = 0;
			d_list->img_new = 0;
			d_list->re_new = 0;
			i = ft_is_mandelbrot(d_list);
			ft_color(d_list, i);
		}
		d_list->x = 0;
	}
	mlx_put_image_to_window(d_list->mlx, d_list->win, d_list->img, 0, 0);
}

/*Sets the color for what is inside and outside
 of malbrot dipending on how far away it goes*/
void	ft_color(t_ps *d_list, int i)
{
	if (i > d_list->max_iter -1)
		ft_mlx_pixel_put(d_list, d_list->x, d_list->y, 0);
	else
		ft_mlx_pixel_put(d_list, d_list->x, d_list->y, i);
}

// Fixes the scaling for the zoom and movement
void	ft_cal_mandelbrot(t_ps *d_list)
{
	d_list->re_pix = 1 * (d_list->x - WIDTH / 2) / (0.5 * d_list->zoom * WIDTH);
	d_list->re_pix = d_list->re_pix + d_list->x_off - 0.5;
	d_list->img_pix = (d_list->y - HEIGHT / 2) / (0.5 * d_list->zoom * HEIGHT);
	d_list->img_pix = d_list->img_pix + d_list->y_off;
}

/*Checks if the real and img numbers are 
part of the mandelbrot and at what point they are not any more*/
int	ft_is_mandelbrot(t_ps *d_list)
{
	int	i;

	i = 0;
	while (i++ < d_list->max_iter)
	{
		d_list->re_old = d_list->re_new;
		d_list->img_old = d_list->img_new;
		d_list->re_new = d_list->re_old * d_list->re_old
			- d_list->img_old * d_list->img_old + d_list->re_pix;
		d_list->img_new = 2 * d_list->re_old
			* d_list->img_old + d_list->img_pix;
		if (d_list->re_new * d_list->re_new
			+ d_list->img_new * d_list->img_new > 4)
			break ;
	}
	return (i);
}
