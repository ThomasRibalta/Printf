/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_char.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thoribal <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/11 14:49:36 by thoribal          #+#    #+#             */
/*   Updated: 2023/10/13 15:06:41 by thoribal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printf_char(t_charact charact, va_list p)
{
	char	c;
	int		i;

	c = (char)va_arg(p, int);
	i = 0;
	if (!(charact.moins) && (charact.largeur > 1))
		i += ft_putnchar(' ', charact.largeur - 1);
	write(1, &c, 1);
	if (charact.moins && (charact.largeur > 1))
		i += ft_putnchar(' ', charact.largeur - 1);
	return (i + 1);
}
