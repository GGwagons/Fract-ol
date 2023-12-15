/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putptr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miturk <miturk@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/25 08:55:08 by miturk            #+#    #+#             */
/*   Updated: 2023/09/25 14:49:14 by miturk           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

long int	ft_putptr(void *ptr)
{
	int					len;
	unsigned long int	address;

	address = (unsigned long int)ptr;
	if (ptr == NULL)
		return (write(1, "(nil)", 5));
	len = write(1, "0x", 2);
	if (address > 15)
	{
		len = len + ft_puthex(address / 16, 'x');
		len = len + ft_puthex(address % 16, 'x');
	}
	else
		len = len + ft_putchar_p("0123456789abcdef"[address % 16]);
	return (len);
}
