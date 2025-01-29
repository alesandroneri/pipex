NAME = libft.a

SRC =	ft_isascii.c \
		ft_memmove.c \
		ft_strchr.c \
		ft_strmapi.c \
		ft_toupper.c \
		ft_isdigit.c \
		ft_memset.c \
		ft_strdup.c \
		ft_strncmp.c \
		ft_atoi.c \
		ft_atol.c \
		ft_isprint.c \
		ft_putchar_fd.c \
		ft_striteri.c \
		ft_strnstr.c \
		ft_bzero.c \
		ft_itoa.c \
		ft_putendl_fd.c \
		ft_strjoin.c \
		ft_strrchr.c \
		ft_calloc.c \
		ft_memchr.c \
		ft_putnbr_fd.c \
		ft_strlcat.c \
		ft_strtrim.c \
		ft_isalnum.c \
		ft_memcmp.c \
		ft_putstr_fd.c \
		ft_strlcpy.c \
		ft_substr.c \
		ft_isalpha.c \
		ft_memcpy.c \
		ft_split.c \
		ft_strlen.c \
		ft_tolower.c \
		ft_lstnew.c \
		ft_lstadd_front.c \
		ft_lstsize.c \
		ft_lstlast.c \
		ft_lstadd_back.c \
		ft_lstdelone.c \
		ft_lstclear.c \
		ft_lstiter.c \
		ft_lstmap.c \
		ft_atol_base.c \
		ft_atoi_base.c \
		ft_printf/ft_printf.c \
		ft_printf/ft_putstr_count.c \
		ft_printf/ft_putnbr_count.c \
		ft_printf/ft_putnbr_base_count.c \
		ft_printf/ft_putchar_count.c \
		ft_printf/ft_put_ptr.c \
		get_next_line/get_next_line.c \
		ft_strcmp.c \
		get_next_line/ft_gnljoin.c 

CC = cc

CC_FLAGS = -g -Wall -Wextra -Werror

OBJS = $(SRC:.c=.o)


$(NAME): $(OBJS)
	@ar rc $(NAME) $(OBJS)

.c.o:
	@$(CC) $(CC_FLAGS) -c $< -o $(<:.c=.o)

all: $(NAME)


clean:
	@rm -f $(OBJS)

fclean: clean
	@rm -rf $(NAME)

re: fclean $(NAME)

run: re
	@clear
	@$(CC) $(CC_FLAGS) main.c $(NAME)
	@./a.out

.PHONY: all clean fclean re run 
