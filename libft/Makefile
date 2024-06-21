CC = cc
CFLAGS = -Wall -Wextra -Werror
RM = rm -rf
NAME = libft.a

LIB_SRCS = ft_putnbr_fd.c ft_putstr_fd.c ft_itoa.c ft_strlen.c
LIB_OBJS = $(LIB_SRCS:.c=.o)

all: $(NAME)

$(NAME): $(LIB_OBJS)
	ar rc $(NAME) $(LIB_OBJS)
	ranlib $(NAME)

clean:
	$(RM) $(LIB_OBJS)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re
