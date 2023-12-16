/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fract_ol.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miturk <miturk@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/15 11:31:39 by miturk            #+#    #+#             */
/*   Updated: 2023/12/16 13:54:14 by miturk           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef	FRACT_OL_H
# define FRACT_OL_H

# include "minilibx-linux/mlx.h"
# include "minilibx-linux/mlx_int.h"
# include "libft/libft.h"
# include "ft_printf/ft_printf.h"
# include <X11/X.h>
# include <X11/keysym.h>
# include <math.h>

#define	X_CLOSE 33
#define K_CLOSE 2



typedef struct	s_ps
{
	void	*mlx;
	void	*win;
	void 	*img;
	void 	*addr;
	int		color;
	int	bits_per_pixel;
	int line_length;
	int endian;
	double x;
	double y;
	double xi;
	double yi;
	double x_off;
	double y_off;
	double zoom;
}				t_ps;

#endif