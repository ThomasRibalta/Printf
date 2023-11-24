/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thoribal <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/13 14:44:28 by thoribal          #+#    #+#             */
/*   Updated: 2023/10/13 15:04:53 by thoribal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <stdlib.h>
# include <unistd.h>
# include <string.h>

size_t	ft_strlen(const char *s);
char	*ft_strchr(const char *s, int c);
char	*ft_itoa(int n);
char	*ft_utostring(unsigned int num);
int		ft_putstr_fd(char *s, int fd, int len);
int		ft_lenhex(size_t n, size_t taille);
int		ft_atoi(const char *str);
int		ft_putnchar(char c, int n);
int		ft_putnbr_base(unsigned long long nbr, char *base);

#endif
