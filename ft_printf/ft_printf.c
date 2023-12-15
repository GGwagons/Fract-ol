/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miturk <miturk@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/25 08:43:16 by miturk            #+#    #+#             */
/*   Updated: 2023/10/02 09:21:04 by miturk           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_strchr(const char *s, int c)
{
	while (*s != '\0')
	{
		if (*s++ == (char)c)
			return (1);
	}
	if ((char)c == '\0')
		return (0);
	return (0);
}

static int	ft_format(va_list args, char format)
{
	long int	len;

	len = 0;
	if (format == '%')
		len = len + ft_putchar_p('%');
	else if (format == 'c')
		len = len + ft_putchar_p(va_arg(args, int));
	else if (format == 's')
		len = len + ft_puts(va_arg(args, char *));
	else if (format == 'p')
		len = len + ft_putptr(va_arg(args, void *));
	else if (format == 'd' || format == 'i')
		len = len + ft_putdi(va_arg(args, int));
	else if (format == 'u')
		len = len + ft_putu(va_arg(args, unsigned int));
	else if (format == 'x')
		len = len + ft_puthex(va_arg(args, unsigned int), 'x');
	else if (format == 'X')
		len = len + ft_puthex(va_arg(args, unsigned int), 'X');
	return (len);
}

int	ft_printf(const char *string, ...)
{
	va_list	args;
	int		i;
	int		len;

	if (string == 0)
		return (-1);
	i = -1;
	len = 0;
	va_start(args, string);
	while (string[++i])
	{
		if (string[i] == '%' && string[i + 1] == '\0')
			return (-1);
		if (string[i] == '%' && 1 == ft_strchr("cspdiuxX%", string[i + 1]))
		{
			len = len + ft_format(args, string[i + 1]);
			i++;
		}
		else
			len = len + ft_putchar_p(string[i]);
	}
	va_end(args);
	return (len);
}
