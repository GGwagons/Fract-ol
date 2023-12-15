/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fract_ol.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miturk <miturk@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/15 11:30:11 by miturk            #+#    #+#             */
/*   Updated: 2023/12/15 15:03:42 by miturk           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fract_ol.h"

int ft_close(int keycode, t_ps *d_list)
{
	(void)keycode;
	if (d_list->img)
		mlx_destroy_image(d_list->mlx, d_list->img);
	if (d_list->win)
		mlx_destroy_window(d_list->mlx, d_list->win);
	if (d_list->addr)
		mlx_destroy_display(d_list->mlx);
	
	exit (1);
}
int main(void)
{
	t_ps *d_list;

	d_list = malloc(sizeof(t_ps));
	d_list->mlx = mlx_init();
	d_list->win = mlx_new_window(d_list->mlx, 1920, 1080, "Fract-ol");
	d_list->img = mlx_new_image(d_list->mlx, 1920, 1080);
	d_list->addr = mlx_get_data_addr(d_list->img, &d_list->bits_per_pixel, &d_list->line_length, &d_list->endian);
	mlx_put_image_to_window(d_list->mlx, d_list->win, d_list->img, 0 ,0);
	mlx_hook (d_list->win, X_CLOSE, 1L<< 8, ft_close, d_list);
	mlx_hook(d_list->win, K_CLOSE, 1L<<0, ft_close, d_list);
	mlx_loop(d_list->mlx);
	return (0);
}