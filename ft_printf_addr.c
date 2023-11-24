/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_addr.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thoribal <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/13 13:56:06 by thoribal          #+#    #+#             */
/*   Updated: 2023/10/16 13:47:27 by thoribal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	sep(t_charact c, size_t n)
{
	int	count;

	count = 0;
	if (c.moins && n)
		count += ft_putstr_fd("0x", 1, 2);
	if ((!c.moins) && c.zero && c.largeur > c.precision && !c.point)
		count += ft_putnchar('0', c.largeur - c.precision);
	else if ((!c.moins) && c.largeur > c.precision)
		count += ft_putnchar(' ', c.largeur - c.precision);
	return (count);
}

int	ft_printf_addr(t_charact c, va_list p)
{
	size_t	n;
	int		lenhex;
	int		count;

	n = va_arg(p, size_t);
	count = 0;
	lenhex = ft_lenhex(n, 16) + 1;
	if (c.precision && !c.point)
		lenhex = 0;
	if (c.precision < lenhex || !c.point)
		c.precision = lenhex;
	c.largeur -= 2 + (!n) + (!n);
	count += sep(c, n);
	if (!n)
		count += ft_putstr_fd("(nil)", 1, 5);
	if (!c.moins && n)
		count += ft_putstr_fd("0x", 1, 2);
	count += ft_putnchar('0', (c.precision - lenhex));
	if (lenhex && n)
		count += ft_putnbr_base(n, HEXAMIN);
	if (c.moins && c.largeur > c.precision)
		count += ft_putnchar(' ', c.largeur - c.precision);
	return (count);
}
