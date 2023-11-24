/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_getcharact.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thoribal <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/10 12:32:57 by thoribal          #+#    #+#             */
/*   Updated: 2023/10/13 14:53:27 by thoribal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static t_charact	new_charact_list(t_charact new)
{
	new.moins = 0;
	new.plus = 0;
	new.largeur = 0;
	new.point = 0;
	new.precision = 0;
	new.espace = 0;
	new.type = 0;
	new.zero = 0;
	new.hashtag = 0;
	return (new);
}

static	t_charact	get_add(t_charact c, char *t)
{
	while (*t != '.' && !(ft_strchr(SETFLAGS, *t)))
	{
		if (*t == ' ')
			c.espace = 1;
		if (*t == '+')
			c.plus = 1;
		if (*t == '#')
			c.hashtag = 1;
		t++;
	}
	return (c);
}

static	t_charact	get_width(t_charact c, char *t, va_list param)
{
	int	i;

	i = 0;
	while (t[i] != '.' && !(ft_strchr(SETFLAGS, t[i])))
	{
		if (t[i] == '-')
			c.moins = 1;
		if (t[i] == '0' && !(t[i - 1] >= '0' && t[i - 1] <= '9'))
			c.zero = 1;
		else if ((t[i] > '0' && t[i] <= '9') || t[i] == '*')
		{
			if (t[i] > '0' && t[i] <= '9')
				c.largeur = ft_atoi(t + i);
			else
				c.largeur = va_arg(param, int);
			break ;
		}
		i++;
	}
	return (c);
}

static t_charact	get_prescision(t_charact c, char *t, va_list param)
{
	int	i;

	i = 0;
	while (t[i] != '.' && !(ft_strchr(SETFLAGS, t[i])))
		i++;
	if (t[i] == '.')
	{
		c.point = 1;
		t++;
		if (t[i] >= '0' && t[i] <= '9')
			c.precision = ft_atoi(t);
		else if (t[i] == '*')
			c.precision = va_arg(param, int);
	}
	return (c);
}

int	ft_getcharact(va_list p, char *t)
{
	t_charact	new;

	new = new_charact_list(new);
	new = get_add(new, t);
	new = get_width(new, t, p);
	while (!(ft_strchr(SETFLAGS,*t)) && *t != '.')
		t++;
	new = get_prescision(new, t, p);
	while (!(ft_strchr(SETFLAGS,*t)) && *t)
		t++;
	new.type = *t;
	return (print_with_type(new, p));
}
