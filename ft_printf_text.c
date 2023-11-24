/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_text.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thoribal <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/13 13:57:26 by thoribal          #+#    #+#             */
/*   Updated: 2023/10/16 14:59:23 by thoribal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printf_text(va_list param, t_charact c)
{
	char	*text;
	int		count;

	text = va_arg(param, char *);
	if (!text && ((c.precision >= 6 && c.point) || (!c.point && !c.precision)))
		text = "(null)";
	count = 0;
	if (!c.point || c.precision > (int)ft_strlen(text))
		c.precision = ft_strlen(text);
	if (!(c.moins) && c.largeur > c.precision && c.zero)
		count += ft_putnchar('0', c.largeur - c.precision);
	else if (!(c.moins) && c.largeur > c.precision)
		count += ft_putnchar(' ', c.largeur - c.precision);
	count += ft_putstr_fd(text, 1, c.precision);
	if (c.moins && c.largeur > c.precision)
		count += ft_putnchar(' ', c.largeur - c.precision);
	return (count);
}
