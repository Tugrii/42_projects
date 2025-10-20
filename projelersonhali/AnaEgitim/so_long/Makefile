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

CFLAGS = -Wall -Wextra -Werror

LIBFT_DIR = library/Libft
LIBFT_ARC = $(LIBFT_DIR)/libft.a
MLX_DIR = library/minilibx-linux
MLX_ARC = $(MLX_DIR)/libmlx.a

SRCS =			src/check_map/check_status.c\
				src/check_map/check_status_utils.c\
				src/check_map/check_not_surrounded_utils.c\
				src/check_map/check_map_is_closed_utils.c\
				src/check_map/check_map_has_one_exit_and_start_utils.c\
				src/check_map/check_file_has_valid_name.c\
				src/check_map/check_valid_path.c\
				src/check_map/check_valid_path_utils.c\
				src/create_map/put_images_to_map.c\
				src/create_map/window_initilaze.c\
				src/create_map/window_initilaze_utils.c\
				src/create_map/error_code.c\
				src/run_map/run_map.c\
				src/run_map/move_player_utils.c\
				src/run_map/move_player.c\
				src/run_map/handle.c\
				src/run_map/find_initial_position.c\
				main.c

NAME = so_long

OBJS = $(SRCS:.c=.o)


all : $(LIBFT_ARC) $(MLX_ARC) $(NAME)

$(LIBFT_ARC) :
	@$(MAKE) -C $(LIBFT_DIR) all

$(MLX_ARC) :
	@$(MAKE) -C $(MLX_DIR) all
$(NAME) : $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) $(LIBFT_ARC) $(MLX_ARC) -L/usr/X11/lib -lXext -lX11 -lm -lbsd -o $(NAME)

clean :
	rm -f $(OBJS)
	@$(MAKE) -C $(LIBFT_DIR) clean
	@$(MAKE) -C $(MLX_DIR) clean

fclean : clean
	rm -f $(OBJS) $(NAME)
	@$(MAKE) -C $(LIBFT_DIR) fclean

re : fclean all

.PHONY : all clean fclean re