# ************************************************************************** #
#                                                                            #
#                                                        :::      ::::::::   #
#   Makefile                                           :+:      :+:    :+:   #
#                                                    +:+ +:+         +:+     #
#   By: tgeler <tgeler@student.42istanbul.com.tr>  +#+  +:+       +#+        #
#                                                +#+#+#+#+#+   +#+           #
#   Created: 2025/12/01 14:26:27 by tgeler            #+#    #+#             #
#   Updated: 2025/12/10 00:32:37 by tgeler           ###   ########.tr       #
#                                                                            #
# ************************************************************************** #

NAME        = pipex
CC          = cc
CFLAGS      = -Wall -Wextra -Werror

LIBFT_DIR  = library/Libft
LIBFT_ARC   = $(LIBFT_DIR)/libft.a

SRCS        =	src/error_functions/print_error.c\
				src/error_functions/arguments_controller.c\
				src/execute/execute.c\
				src/exit_with_clean_way/exit_with_clean_way.c\
				src/path_process/path_creater/path_creater.c\
				src/path_process/path_finder/path_finder.c\
				main.c
OBJS        = $(SRCS:.c=.o)

all: $(LIBFT_ARC) $(NAME)

$(LIBFT_ARC):
	@$(MAKE) -C $(LIBFT_DIR) all

$(NAME): $(OBJS) $(LIBFT_ARC)
	$(CC) $(CFLAGS) $(OBJS) $(LIBFT_ARC) -o $(NAME)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJS)
	@$(MAKE) -C $(LIBFT_DIR) clean

fclean: clean
	rm -f $(NAME)
	@$(MAKE) -C $(LIBFT_DIR) fclean

re: fclean all

.PHONY: all clean fclean re