# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tgeler <tgeler@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/10/02 17:01:15 by tgeler            #+#    #+#              #
#    Updated: 2025/10/02 17:01:15 by tgeler           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = cc

CFLAGS = -Wall -Wextra -Werror

SRCS = get_next_line.c\
		get_next_line_utils.c

OBJS = $(SRCS:.c=.o)

NAME = get_next_line.a

all: $(NAME)

$(NAME): $(OBJS)
	ar rcs $(NAME) $(OBJS)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

test: $(NAME) main.c
	$(CC) $(CFLAGS) main.c get_next_line.a -o test_program
	./test_program

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME) test_program

re: fclean all

.PHONY: all clean fclean re test