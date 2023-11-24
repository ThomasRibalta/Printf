/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_num.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thoribal <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/13 13:56:35 by thoribal          #+#    #+#             */
/*   Updated: 2023/10/16 15:04:01 by thoribal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	aff_signe(int n)
{
	if (n == 2)
		return (ft_putnchar('-', 1));
	else if (n == 1)
		return (ft_putnchar('+', 1));
	return (0);
}

int	ft_print_num(t_charact c, char *str, int len, int n)
{
	int	count;

	count = 0;
	c.largeur -= (c.espace || c.plus);
	if (c.plus && c.type != 'u' && c.zero && !c.point)
		count += aff_signe(c.plus);
	else if (c.espace && (c.plus != 2) && n != -2147483648)
		count += ft_putnchar(' ', 1);
	if (!(c.moins) && c.zero && c.largeur > c.precision && !c.point)
		count += ft_putnchar('0', c.largeur - c.precision);
	else if (!(c.moins) && c.largeur > c.precision)
		count += ft_putnchar(' ', c.largeur - c.precision);
	if (c.plus && c.type != 'u' && (!c.zero || c.point))
		count += aff_signe(c.plus);
	count += ft_putnchar('0', c.precision - len);
	count += ft_putstr_fd(str, 1, len);
	if (c.moins && c.largeur > c.precision)
		count += ft_putnchar(' ', c.largeur - c.precision);
	return (count);
}

int	ft_printf_num(t_charact c, va_list p)
{
	char	*str;
	long	n;
	int		count;
	int		len;

	n = va_arg(p, int);
	count = 0;
	if (n < 0 && c.type != 'u')
	{
		c.plus = 2 * (n != -2147483648);
		n *= -1;
	}
	if (c.type != 'u')
		str = ft_itoa(n);
	else
		str = ft_utostring(n);
	len = (int) ft_strlen(str);
	if (*str == '0' && !c.precision && c.point)
		len = 0;
	if (len > c.precision)
		c.precision = len;
	count += ft_print_num(c, str, len, n);
	free(str);
	return (count);
}
