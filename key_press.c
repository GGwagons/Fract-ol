/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_press.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miturk <miturk@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/20 15:39:35 by miturk            #+#    #+#             */
/*   Updated: 2023/12/29 16:41:31 by miturk           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fract_ol.h"

int	key_hook(int key, t_ps *d_list)
{
	if (key == XK_Escape)
		ft_close(d_list);
	else if (key == XK_Up)
		d_list->y_off = d_list->y_off - (0.5 / d_list->zoom);
	else if (key == XK_Down)
		d_list->y_off = d_list->y_off + (0.5 / d_list->zoom);
	else if (key == XK_Right)
		d_list->x_off = d_list->x_off + (0.5 / d_list->zoom);
	else if (key == XK_Left)
		d_list->x_off = d_list->x_off - (0.5 / d_list->zoom);
	ft_draw_img(d_list);
	return (0);
}

int	ft_zoom(int key, int x, int y, t_ps *d_list)
{
	if (key == Button4 || key == Button5)
	{
		if (x <= WIDTH && y <= HEIGHT && x >= 0 && y >= 0)
		{
			if (key == Button5 && d_list->zoom > 0.00000001)
				d_list->zoom = d_list->zoom * 0.95;
			else if (key == Button4 && d_list->zoom < 2147483647)
				d_list->zoom = d_list->zoom * 1.05;
			else
				return (0);
		}
	}
	ft_draw_img(d_list);
	return (0);
}

int	ft_arrow_position(int x, int y, t_ps *d_list)
{
	d_list->arrow_x = x;
	d_list->arrow_y = y;
	return (0);
}

int	ft_close(t_ps *d_list)
{
	if (d_list->img)
		mlx_destroy_image(d_list->mlx, d_list->img);
	if (d_list->win)
		mlx_destroy_window(d_list->mlx, d_list->win);
	if (d_list->addr)
		mlx_destroy_display(d_list->mlx);
	free(d_list->mlx);
	free(d_list);
	exit (1);
}
