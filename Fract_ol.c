/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fract_ol.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miturk <miturk@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/15 11:30:11 by miturk            #+#    #+#             */
/*   Updated: 2023/12/20 18:09:48 by miturk           ###   ########.fr       */
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

//I may not use this
void	ft_mlx_pixel_put(t_ps *d_list, int x, int y, int i)
{
	int offset;

	offset = (y * d_list->line_length) + ((d_list->bits_per_pixel / 8) * x);
	*(unsigned int*)(d_list->addr + offset) = d_list->color * (i % 255);
	
}


void	set_fractol(t_ps *d_list)
{
	d_list->x = 0;
	d_list->y = 0;
	d_list->x_off = 0.0;
	d_list->y_off = 0.0;
	d_list->zoom = 1;
	d_list->color = 0x250697;
	d_list->endian = 0;
	d_list->line_length = 0;
	d_list->max_iter = 100;
	d_list->c_real = 0.0;
	d_list->c_img = 0.0;
	d_list->z_real = 0.0;
	d_list->z_img = 0.0;
	d_list->arrow_x = 0;
	d_list->arrow_y = 0;
	d_list->name = JULIA;

	//else if (d_list->name == JULIA)
	//	set_julia_fractol(d_list);
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
	d_list->img = mlx_new_image(d_list->mlx, WIDTH, HEIGHT);
	d_list->win = mlx_new_window(d_list->mlx, WIDTH, HEIGHT, "Fract_ol");
	d_list->addr = mlx_get_data_addr(d_list->img, &d_list->bits_per_pixel, &d_list->line_length, &d_list->endian);
	if (!d_list->mlx || !d_list->win || !d_list->addr)
		ft_close(d_list);
}


//	DISPLAY AND CALCULATE IMAGE!!


int	ft_draw_img(t_ps *d_list)
{
	//if (d_list->name == 1)
	//	ft_mandelbrot (d_list);
	//else if (d_list->name == 2)
		ft_julia(d_list);
	mlx_put_image_to_window(d_list->mlx, d_list->win, d_list->img, d_list->x, d_list->y);
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
	ft_draw_img(d_list);
	mlx_hook (d_list->win, 17, 0L, ft_close, d_list);
	mlx_key_hook(d_list->win, key_hook, d_list);
	mlx_hook(d_list->win, 06, 1L<<6, ft_arrow_position, d_list);
	mlx_hook(d_list->win, 04, 1L<<2, ft_zoom, d_list);
	mlx_loop(d_list->mlx);
	ft_close(d_list);
	free(d_list);
	return (0);
}
/*
int	main(int argc, char *argv[])
{
	t_ps *d_list;

	if (argc != 2)
	{
		ft_putendl_fd("Incorect fractol\n", 1);
		return (0);
	}
	d_list = malloc(sizeof(t_ps));
	if (!d_list)
		return (-1);
	set_fractol(d_list);
	init_mlx(d_list);
	ft_draw_img(d_list);
	mlx_hook (d_list->win, 17, 0L, ft_close, d_list);
	mlx_key_hook(d_list->win, key_hook, d_list);
	mlx_hook(d_list->win, 06, 1L<<6, ft_arrow_position, d_list);
	mlx_hook(d_list->win, 04, 1L<<2, ft_zoom, d_list);
	mlx_loop(d_list->mlx);
	ft_close(d_list);
	free(d_list);
	return (0);	
}*/