# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tgeler <tgeler@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/06/26 14:43:31 by tgeler            #+#    #+#              #
#    Updated: 2025/06/28 01:15:09 by tgeler           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = cc

CFLAGS = -Wall -Wextra -Werror

SRCS = ft_atoi.c \
	ft_bzero.c\
	ft_calloc.c\
	ft_isalnum.c\
	ft_isalpha.c\
	ft_isascii.c\
	ft_isdigit.c\
	ft_isprint.c\
	ft_itoa.c\
	ft_memchr.c\
	ft_memcpy.c\
	ft_memmove.c\
	ft_memset.c\
	ft_memcmp.c\
	ft_putchar_fd.c\
	ft_putnbr_fd.c\
	ft_putstr_fd.c\
	ft_putendl_fd.c\
	ft_split.c\
	ft_strchr.c\
	ft_strdup.c\
	ft_striteri.c\
	ft_strjoin.c\
	ft_strlcat.c\
	ft_strlcpy.c\
	ft_strlen.c\
	ft_strmapi.c\
	ft_strncmp.c\
	ft_strnstr.c\
	ft_strrchr.c\
	ft_strtrim.c\
	ft_substr.c\
	ft_tolower.c\
	ft_toupper.c

BONUS_SRCS = ft_lstadd_back.c\
	ft_lstadd_front.c\
	ft_lstlast.c\
	ft_lstnew.c\
	ft_lstsize.c\

# .c dosyalarının karşılık gelen .o dosyaları
OBJS = $(SRCS:.c=.o)
BONUS_OBJS = $(BONUS_SRCS:.c=.o)

# Oluşacak kütüphane adı
NAME = libft.a

# Varsayılan hedef: Kütüphane oluştur
all: $(NAME)

# Statik kütüphane oluştur
$(NAME): $(OBJS)
	ar rcs $(NAME) $(OBJS)

bonus: $(OBJS) $(BONUS_OBJS)
	ar rcs $(NAME) $(OBJS) $(BONUS_OBJS)
# .o dosyalarını derle
%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

# Test programını derle ve çalıştır
test: $(NAME) main.c
	$(CC) $(CFLAGS) main.c -L. -lft -o test_program
	./test_program

# Nesne dosyalarını temizle
clean:
	rm -f $(OBJS)

# Kütüphane ve test programını temizle
fclean: clean
	rm -f $(NAME) test_program

# Temizle ve yeniden derle
re: fclean all

.PHONY: all clean fclean re test
