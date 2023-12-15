/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miturk <miturk@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/19 10:30:51 by miturk            #+#    #+#             */
/*   Updated: 2023/12/12 22:44:42 by miturk           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include <ctype.h>
# include <limits.h>
# include <stdarg.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <unistd.h>

int			ft_printf(const char *format, ...);
int			ft_putchar_p(char c);
int			ft_puts(char *s);
int			ft_putu(unsigned int nbr);
int			ft_putdi(int nbr);
int			ft_puthex(unsigned long int nbr, char format);
long int	ft_putptr(void *ptr);

#endif
