/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putu.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miturk <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/25 08:47:35 by miturk            #+#    #+#             */
/*   Updated: 2023/09/25 08:47:36 by miturk           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putu(unsigned int nbr)
{
	int	len;

	len = 0;
	if (nbr >= 10)
	{
		len = len + ft_putu (nbr / 10);
		len = len + ft_putu (nbr % 10);
	}
	else
	{
		ft_putchar_p (nbr + '0');
		len++;
	}
	return (len);
}
