/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thoribal <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/29 16:46:53 by thoribal          #+#    #+#             */
/*   Updated: 2023/10/16 13:45:06 by thoribal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>
#include <unistd.h>

void	ft_putnbr_base_recursive(unsigned long long nbr, char *base, int *count)
{
	int	base_len;

	base_len = ft_strlen(base);
	if (nbr >= (unsigned long long)base_len)
	{
		ft_putnbr_base_recursive(nbr / base_len, base, count);
	}
	write(1, base + (nbr % base_len), 1);
	(*count)++;
}

int	ft_putnbr_base(unsigned long long nbr, char *base)
{
	int	count;

	if (ft_strlen(base) < 2)
	{
		return (0);
	}
	if (nbr == 0)
	{
		write(1, base, 1);
		return (1);
	}
	else
	{
		count = 0;
		ft_putnbr_base_recursive(nbr, base, &count);
		return (count);
	}
}
