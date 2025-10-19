# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tgeler <tgeler@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/10/02 22:31:16 by tgeler            #+#    #+#              #
#    Updated: 2025/10/02 22:31:16 by tgeler           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = cc

CFLAGS = -Wall -Wextra -Werror -g

LIBFT_SRCS = library/Libft/ft_atoi.c \
	library/Libft/ft_bzero.c\
	library/Libft/ft_calloc.c\
	library/Libft/ft_isalnum.c\
	library/Libft/ft_isalpha.c\
	library/Libft/ft_isascii.c\
	library/Libft/ft_isdigit.c\
	library/Libft/ft_isprint.c\
	library/Libft/ft_itoa.c\
	library/Libft/ft_memchr.c\
	library/Libft/ft_memcpy.c\
	library/Libft/ft_memmove.c\
	library/Libft/ft_memset.c\
	library/Libft/ft_memcmp.c\
	library/Libft/ft_putchar_fd.c\
	library/Libft/ft_putnbr_fd.c\
	library/Libft/ft_putstr_fd.c\
	library/Libft/ft_putendl_fd.c\
	library/Libft/ft_split.c\
	library/Libft/ft_strchr.c\
	library/Libft/ft_strdup.c\
	library/Libft/ft_striteri.c\
	library/Libft/ft_strjoin.c\
	library/Libft/ft_strlcat.c\
	library/Libft/ft_strlcpy.c\
	library/Libft/ft_strlen.c\
	library/Libft/ft_strmapi.c\
	library/Libft/ft_strncmp.c\
	library/Libft/ft_strnstr.c\
	library/Libft/ft_strrchr.c\
	library/Libft/ft_strtrim.c\
	library/Libft/ft_substr.c\
	library/Libft/ft_tolower.c\
	library/Libft/ft_toupper.c\
	library/Libft/ft_lstadd_front_bonus.c\
	library/Libft/ft_lstlast_bonus.c\
	library/Libft/ft_lstnew_bonus.c\
	library/Libft/ft_lstsize_bonus.c\
	library/Libft/ft_lstadd_back_bonus.c

FT_PRINTF_SRCS = library/ft_printf/ft_printf.c\
	library/ft_printf/helper_f1.c

GNL_SRCS = library/get_next_line/get_next_line.c\
		library/get_next_line/get_next_line_utils.c

SO_LONG_SRCS = src/create_map/error_code.c\
				src/create_map/put_images_to_map.c\
				src/create_map/window_initilaze.c\
				src/create_map/window_initilaze_utils.c\
				src/check_map/check_status.c\
				src/check_map/check_status_utils.c\
				src/check_map/check_not_surrounded_utils.c\
				src/check_map/check_map_is_closed_utils.c\
				src/check_map/check_map_has_one_exit_and_start_utils.c\
				src/check_map/check_file_has_valid_name.c\
				src/check_map/check_valid_path.c\
				src/check_map/check_valid_path_utils.c\
				src/run_map/run_map.c\
				src/run_map/move_player_utils.c\
				src/run_map/move_player.c\
				src/run_map/handle.c\
				src/run_map/find_initial_position.c
NAME = so_long

SRCS = main.c $(LIBFT_SRCS) $(FT_PRINTF_SRCS) $(GNL_SRCS) $(SO_LONG_SRCS)

OBJS = $(SRCS:.c=.o)

MLX_DIR = library/minilibx-linux
MLX = $(MLX_DIR)/libmlx.a

all: $(NAME)

$(NAME): $(OBJS) $(MLX)
	$(CC) $(CFLAGS) $^ -L$(MLX_DIR) -lmlx -lXext -lX11 -lm -lz -o $(NAME)

$(MLX):
	$(MAKE) -C $(MLX_DIR)

test: so_long
	./so_long maps/test.ber

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJS)
	$(MAKE) -C $(MLX_DIR) clean

fclean: clean
	rm -f $(NAME)
	$(MAKE) -C $(MLX_DIR) clean

re: fclean all

.PHONY: all clean fclean re
