/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thoribal <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/10 12:33:03 by thoribal          #+#    #+#             */
/*   Updated: 2023/10/13 16:24:04 by thoribal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	print_with_type(t_charact c, va_list p)
{
	if (c.type == '%')
		return (ft_putnchar('%', 1));
	if (c.type == 'c')
		return (ft_printf_char(c, p));
	if (c.type == 's')
		return (ft_printf_text(p, c));
	if (c.type == 'x' || c.type == 'X')
		return (ft_printf_hex(c, p));
	if (c.type == 'u' || c.type == 'i' || c.type == 'd')
		return (ft_printf_num(c, p));
	if (c.type == 'p')
		return (ft_printf_addr(c, p));
	return (0);
}

int	ft_printf(const char *text, ...)
{
	va_list	parameters;
	int		total_len;

	va_start(parameters, text);
	total_len = 0;
	while (*text)
	{
		if (*text == '%')
		{
			text++;
			total_len += ft_getcharact(parameters, (char *) text);
			while (*text && !(ft_strchr(SETFLAGS, *text)))
				text++;
		}
		else
		{
			total_len += 1;
			write(1, text, 1);
		}
		text++;
	}
	va_end(parameters);
	return (total_len);
}
