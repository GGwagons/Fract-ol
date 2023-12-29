/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fract_ol.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miturk <miturk@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/15 11:31:39 by miturk            #+#    #+#             */
/*   Updated: 2023/12/29 16:45:45 by miturk           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACT_OL_H
# define FRACT_OL_H

# include "minilibx-linux/mlx.h"
# include "minilibx-linux/mlx_int.h"
# include "libft/libft.h"
# include "ft_printf/ft_printf.h"
# include <X11/X.h>
# include <X11/keysym.h>
# include <math.h>

# define WIDTH 400
# define HEIGHT 400
# define MANDELBROT 1
# define JULIA 2

typedef struct s_ps
{
	int		i;
	int		name;
	void	*mlx;
	void	*win;
	void	*img;
	void	*addr;
	int		color;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
	int		max_iter;
	double	x;
	double	y;
	double	x_off;
	double	y_off;
	double	zoom;
	double	z_img;
	double	z_real;
	double	re_new;
	double	img_new;
	double	c_img;
	double	c_real;
	double	arrow_x;
	double	arrow_y;

}				t_ps;

int		ft_close(t_ps *d_list);
void	ft_mlx_pixel_put(t_ps *d_list, int x, int y, int color);
void	set_fractol(t_ps *d_list);
void	init_mlx(t_ps *d_list);
int		ft_draw_img(t_ps *d_list);
int		key_hook(int key, t_ps *d_list);
int		ft_zoom(int key, int x, int y, t_ps *d_list);
int		ft_arrow_position(int x, int y, t_ps *d_list);

void	ft_cal_mandelbrot(t_ps *d_list);
void	ft_mandelbrot(t_ps	*d_list);
void	ft_color(t_ps *d_list, int i);
int		ft_is_mandelbrot(t_ps *d_list);
void	set_mandelbrot_fractol(t_ps *d_list);

void	ft_julia(t_ps *d_list);
int		ft_is_julia(t_ps *d_list);
void	set_julia_fractol(t_ps *d_list, char **agrv);

int		ft_check_args(char **argv, t_ps *d_list);
double	ft_atof(const char *s);
void	ft_custom(t_ps *d_list, char **argv);
void	ft_num_check1(t_ps *d_list, char **argv);
void	ft_num_check2(t_ps *d_list, char **argv);

#endif