/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fract_ol.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miturk <miturk@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/15 11:30:11 by miturk            #+#    #+#             */
/*   Updated: 2023/12/16 15:01:20 by miturk           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fract_ol.h"

int ft_close(t_ps *d_list)
{
	if (d_list->img)
		mlx_destroy_image(d_list->mlx, d_list->img);
	if (d_list->win)
		mlx_destroy_window(d_list->mlx, d_list->win);
	if (d_list->addr)
		mlx_destroy_display(d_list->mlx);
	free(d_list);
	exit (1);
}

void	my_mlx_pixel_put(t_ps *d_list, int x, int y, int color)
{
	void *dest;

	dest = d_list->addr + (y * d_list->line_length + x * (d_list->bits_per_pixel / 8));
	*(unsigned int*)dest = color;
	mlx_put_image_to_window(d_list->mlx, d_list->win, d_list->img, 0, 0);
}


void	set_fractol(t_ps *d_list)
{
	d_list->x = 0;
	d_list->y = 0;
	d_list->x_off = 0;
	d_list->y_off = 0;
	d_list->zoom = 10;
	d_list->color = 0xB21D1D;
	d_list->endian = 0;
	d_list->line_length = 0;
	d_list->bits_per_pixel = 0;
}

void	init_mlx(t_ps *d_list)
{
	d_list->mlx = mlx_init();
	if (!d_list->mlx)
	{
		free(d_list->mlx);
		free(d_list);
		exit(1);
	}
	d_list->win = mlx_new_window(d_list->mlx, 1920, 1080, "Fract_ol");
	d_list->img = mlx_new_image(d_list->mlx, 1920, 1080);
	d_list->addr = mlx_get_data_addr(d_list->img, &d_list->bits_per_pixel, &d_list->line_length, &d_list->endian);
	if (!d_list->mlx || !d_list->win || !d_list->addr)
		ft_close(d_list);
}

void	ft_draw_img(t_ps *d_list)
{
	while (d_list->x != 150 && d_list->y != 150)
	{
		
		my_mlx_pixel_put(d_list, d_list->x, d_list->y, d_list->color);
		d_list->x++;
		while (d_list->y != 50)
		{
			if(d_list->y == 0 || d_list->y == 50 || d_list->y == 100 || d_list->y == 150)
			{	
				my_mlx_pixel_put(d_list, d_list->x, d_list->y, d_list->color);
				d_list->x++;
			}	
			d_list->y++;

		}
	}
	
}

int	key_hook(int key, t_ps *d_list)
{
	if (key == XK_Escape)
		ft_close(d_list);
	else if (key == XK_Up)
		d_list->y_off = d_list->y_off - 100 / d_list->zoom;
	else if (key == XK_Down)
		d_list->y_off = d_list->y_off + 100 / d_list->zoom;
	else if (key == XK_Right)
		d_list->x_off = d_list->x_off + 100 / d_list->zoom;
	else if (key == XK_Left)
		d_list->x_off = d_list->x_off - 100 / d_list->zoom;
	ft_draw_img(d_list);
	return (0);
}

int main(void)
{
	t_ps *d_list;

	d_list = malloc(sizeof(t_ps));
	if (!d_list)
        return (1);
	set_fractol(d_list);
	init_mlx(d_list);
	mlx_hook (d_list->win, X_CLOSE, 0L, ft_close, d_list);
	mlx_key_hook(d_list->win, key_hook, d_list);
	//mlx_put_image_to_window(d_list->mlx, d_list->win, d_list->img, 0, 0);
	ft_draw_img(d_list);
	mlx_loop(d_list->mlx);
	ft_close(d_list);
	free(d_list);
	return (0);
}