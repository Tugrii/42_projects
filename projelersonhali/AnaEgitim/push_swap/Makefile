# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tgeler <tgeler@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/10/20 22:14:27 by tgeler            #+#    #+#              #
#    Updated: 2025/10/20 22:14:27 by tgeler           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

C = cc
CFLAGS = -Wall -Wextra -Werror

NAME = push_swap

LIBFT_DIR = Libft
LIBFT_ARC = $(LIBFT_DIR)/libft.a

SRCS = push_swap.c\
		push_swap_utils.c\
		main.c

OBJS = $(SRCS:.c=.o)

all : $(LIBFT_ARC) $(NAME)

$(LIBFT_ARC) :
	@$(MAKE) -C $(LIBFT_DIR) all

$(NAME) : $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) $(LIBFT_ARC) -o $(NAME)

clean :
	rm -f $(OBJS)
	@$(MAKE) -C $(LIBFT_DIR) clean

fclean : clean
	rm -f $(OBJS) $(NAME)
	@$(MAKE) -C $(LIBFT_DIR) fclean

re : fclean all
