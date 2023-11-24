/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_hex.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thoribal <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/13 13:56:20 by thoribal          #+#    #+#             */
/*   Updated: 2023/10/16 14:10:17 by thoribal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printtag(t_charact c)
{
	if (c.type == 'x')
		return (ft_putstr_fd("0x", 1, 2));
	else if (c.type == 'X')
		return (ft_putstr_fd("0X", 1, 2));
	return (0);
}

int	sep(t_charact c, unsigned int n)
{
	int	count;

	count = 0;
	if (c.hashtag && c.zero && n)
	{
		c.largeur -= ft_printtag(c);
		count += 2;
	}
	if ((!c.moins) && c.zero && c.largeur > c.precision && !c.point)
		count += ft_putnchar('0', c.largeur - c.precision);
	else if ((!c.moins) && c.largeur > c.precision)
		count += ft_putnchar(' ', c.largeur - c.precision);
	if (c.hashtag && !c.zero && n)
	{
		c.largeur -= ft_printtag(c);
		count += 2;
	}
	return (count);
}

int	ft_printf_hex(t_charact c, va_list p)
{
	int				lenhex;
	int				count;
	unsigned int	n;

	n = va_arg(p, unsigned int);
	lenhex = ft_lenhex(n, 16) + 1;
	count = 0;
	if (!c.precision && !n && c.point)
		lenhex = 0;
	if (c.precision < 0 || c.precision < lenhex || !c.point)
		c.precision = lenhex;
	count += sep(c, n);
	count += ft_putnchar('0', (c.precision - lenhex));
	if (c.type == 'x' && lenhex)
		count += ft_putnbr_base(n, HEXAMIN);
	else if (c.type == 'X' && lenhex)
		count += ft_putnbr_base(n, HEXAMAJ);
	if (c.moins && c.largeur > c.precision)
		count += ft_putnchar(' ', c.largeur - c.precision);
	return (count);
}
