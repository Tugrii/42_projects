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

SRCS = 	main.c\
		src/check_status/arguments_controller.c\
		src/check_status/check_all_are_number.c\
		src/check_status/check_is_over_limit.c\
		src/check_status/check_is_there_duplicate.c\
		src/check_status/check_is_sorted.c\
		src/check_status/check_status.c\
		src/check_status/specilazed_control.c\
		src/error_functions/print_error.c\
		src/execute/radix.c\
		src/execute/simple.c\
		src/execute/start_to_execute.c\
		src/exit_with_clean_way/exit_with_clean_way.c\
		src/parser/convert_tointlinkedlist.c\
		src/parser/split_the_arguments.c\
		src/stack_operations/pa.c\
		src/stack_operations/pb.c\
		src/stack_operations/ra.c\
		src/stack_operations/rb.c\
		src/stack_operations/rr.c\
		src/stack_operations/rra.c\
		src/stack_operations/rrb.c\
		src/stack_operations/rrr.c\
		src/stack_operations/sa.c\
		src/stack_operations/sb.c\
		src/stack_operations/ss.c

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
