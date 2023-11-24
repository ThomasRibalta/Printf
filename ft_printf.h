/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thoribal <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/13 14:44:53 by thoribal          #+#    #+#             */
/*   Updated: 2023/10/13 16:26:01 by thoribal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include "libft/libft.h"
# include <stdarg.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <string.h>

# define SETFLAGS "cspdiuxX%"
# define HEXAMIN "0123456789abcdef"
# define HEXAMAJ "0123456789ABCDEF"

typedef struct s_characteristic
{
	char	type;
	int		moins;
	int		plus;
	int		largeur;
	int		point;
	int		precision;
	int		espace;
	int		zero;
	int		hashtag;

}	t_charact;

int	ft_printf_char(t_charact charact, va_list p);
int	ft_printf_text(va_list param, t_charact c);
int	ft_printf_num(t_charact c, va_list p);
int	ft_printf_hex(t_charact c, va_list p);
int	print_with_type(t_charact c, va_list p);
int	ft_printf_addr(t_charact c, va_list p);
int	ft_getcharact(va_list p, char *t);
int	ft_printf(const char *text, ...);

#endif
