/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_uToString.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thoribal <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/13 15:00:58 by thoribal          #+#    #+#             */
/*   Updated: 2023/10/13 15:03:27 by thoribal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_reversestring(char *str, int length)
{
	char	temp;
	int		start;
	int		end;

	start = 0;
	end = length - 1;
	while (start < end)
	{
		temp = str[start];
		str[start] = str[end];
		str[end] = temp;
		start++;
		end--;
	}
}

char	*ft_utostring(unsigned int num)
{
	int		maxdigits;
	int		i;
	char	*str;

	maxdigits = 10;
	str = malloc(maxdigits + 1);
	if (!str)
		return (NULL);
	i = 0;
	if (num == 0)
		str[i++] = '0';
	else
	{
		while (num > 0)
		{
			str[i++] = (num % 10) + '0';
			num /= 10;
		}
	}
	ft_reversestring(str, i);
	str[i] = '\0';
	return (str);
}
