/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putdi.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miturk <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/25 08:45:57 by miturk            #+#    #+#             */
/*   Updated: 2023/09/25 08:45:59 by miturk           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putdi(int nbr)
{
	int	len;

	len = 0;
	if (nbr == -2147483648)
	{
		ft_puts("-2147483648");
		return (11);
	}
	if (nbr < 0)
	{
		ft_putchar_p('-');
		nbr *= -1;
		len++;
	}
	if (nbr >= 10)
	{
		len = len + ft_putdi(nbr / 10);
		len = len + ft_putdi(nbr % 10);
	}
	else
	{
		ft_putchar_p(nbr + '0');
		len++;
	}
	return (len);
}
