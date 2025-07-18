# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tgeler <tgeler@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/07/13 20:08:21 by tgeler            #+#    #+#              #
#    Updated: 2025/07/13 20:08:21 by tgeler           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = cc

CFLAGS = -Wall -Wextra -Wextra

SRCS = ft_printf.c\
	helper_f1.c\
	Libft/ft_putchar_fd.c\
	Libft/ft_putnbr_fd.c\
	Libft/ft_putstr_fd.c\
	Libft/ft_strchr.c\
	Libft/ft_strlen.c
	

OBJS = $(SRCS:.c=.o)

NAME = libftprintf.a

all: $(NAME)

$(NAME): $(OBJS)
	ar rcs $(NAME) $(OBJS)


%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

test: $(NAME) main.c
	$(CC) $(CFLAGS) main.c libftprintf.a -o test_program
	./test_program

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME) test_program

re: fclean all

.PHONY: all clean fclean re test