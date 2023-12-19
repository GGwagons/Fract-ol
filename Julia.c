/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Julia.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miturk <miturk@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/15 13:41:00 by miturk            #+#    #+#             */
/*   Updated: 2023/12/19 18:50:37 by miturk           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fract_ol.h"

void	ft_julia(t_ps *d_list)
{
	int	i;
	
	
	d_list->y = 0;
	while (d_list->y++ <= HEIGHT)
	{
		d_list->x = 0;
		while (d_list->x++ <= WIDTH)
		{
			ft_cal_julia(d_list);
			d_list->img_old = 0;
			d_list->re_old = 0;
			d_list->img_new = 0;
			d_list->re_new = 0;
			i = ft_is_julia(d_list);
			ft_color(d_list, i);
		}
	}
	mlx_put_image_to_window(d_list->mlx, d_list->win, d_list->img, 0, 0);
}
void	ft_cal_julia(t_ps *d_list)
{
	d_list->re_pix = 1 * (d_list->x - WIDTH / 2) / (0.5 * d_list->zoom * WIDTH);
	d_list->re_pix = d_list->re_pix + d_list->x_off - 0.5;
	d_list->img_pix = (d_list->y - HEIGHT / 2) / (0.5 * d_list->zoom * HEIGHT);
	d_list->img_pix = d_list->img_pix + d_list->y_off;
}
int	ft_is_julia(t_ps *d_list)
{
	int	i;
	double temp;

	i = 0;
	while (i++ < d_list->max_iter)
	{
		temp = d_list->re_old;
		d_list->re_new = d_list->re_old * d_list->re_old - d_list->img_old * d_list->img_new + d_list->re_pix;
		d_list->img_new = 2 * d_list->re_old * temp * d_list->img_old + d_list->img_pix;
		d_list->re_new = temp;
		if (d_list->re_new * d_list->re_new
			+ d_list->img_new * d_list->img_new > 4)
			break ;
	}
	return (i);
}