CC = gcc
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
	ft_lstadd_back.c\
	ft_lstadd_front.c\
	ft_lstclear.c\
	ft_lstdelone.c\
	ft_lstiter.c\
	ft_lstlast.c\
	ft_lstmap.c\
	ft_lstnew.c\
	ft_lstsize.c\
	ft_memchr.c\
	ft_memcpy.c\
	ft_memmove.c\
	ft_memset.c\
	ft_putchar_fd.c\
	ft_putnbr_fd.c\
	ft_putstr_fd.c\
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


# .c dosyalarının karşılık gelen .o dosyaları
OBJS = $(SRCS:.c=.o)

# Oluşacak program ya da kütüphane adı (örnek: libft.a yerine program adı)
NAME = libft.a

# Varsayılan hedef: Kütüphane oluştur
all: $(NAME)

# Statik kütüphane oluşturmak için arşivle (ar)
$(NAME): $(OBJS)
	ar rcs $(NAME) $(OBJS)

# .o dosyalarını derle (her .o için ayrı kural)
%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

# Nesne dosyalarını temizle
clean:
	rm -f $(OBJS)

# Hem clean hem kütüphaneyi sil
fclean: clean
	rm -f $(NAME)

# Temizle ve tekrar derle
re: fclean all

.PHONY: all clean fclean re

# Test programını derle
test: $(NAME) main.c
	$(CC) $(CFLAGS) main.c -L. -lft -o test_program

