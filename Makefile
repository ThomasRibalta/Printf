SRCS= ft_getcharact.c ft_printf_addr.c ft_printf.c ft_printf_char.c ft_printf_hex.c ft_printf_num.c ft_printf_text.c libft/ft_itoa.c libft/ft_lenhex.c libft/ft_uToString.c \
        libft/ft_strlen.c libft/ft_strchr.c libft/ft_putstr_fd.c libft/ft_atoi.c libft/ft_putnbr_base.c libft/ft_putnchar.c
OBJS= $(SRCS:.c=.o)

BONUS= ft_getcharact.c ft_printf_addr.c ft_printf.c ft_printf_char.c ft_printf_hex.c ft_printf_num.c ft_printf_text.c libft/ft_itoa.c libft/ft_lenhex.c libft/ft_uToString.c \
        libft/ft_strlen.c libft/ft_strchr.c libft/ft_putstr_fd.c libft/ft_atoi.c libft/ft_putnbr_base.c libft/ft_putnchar.c
BONUS_OBJS= $(BONUS:.c=.o)

CC= gcc
RM= rm -f
CFLAGS= -Wall -Wextra -Werror -I.

NAME= libftprintf.a

all: $(NAME)

$(NAME): $(OBJS)
	ar rcs $(NAME) $(OBJS)

clean:
	$(RM) $(OBJS) $(BONUS_OBJS)

fclean:	clean
	$(RM) $(NAME)

re: fclean $(NAME)

.PHONY:	all clean fclean re bonus
