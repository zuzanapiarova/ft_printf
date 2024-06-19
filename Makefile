CC = cc
CFLAGS = -Wall -Wextra -Werror
RM = rm -rf
NAME = libftprintf.a
TEST_PROG = test_ftprintf
TEST_SRC = test_ftprintf.c

LIB_SRCS = ft_printf.c print_char.c print_string.c print_percent.c ft_printf.c
LIB_OBJS = $(LIB_SRCS:.c=.o)

all: $(NAME) $(TEST_PROG)

$(NAME): $(LIB_OBJS)
	ar rc $(NAME) $(LIB_OBJS)
	ranlib $(NAME)

$(TEST_PROG): $(TEST_SRC) $(NAME)
	$(CC) $(CFLAGS) -o $(TEST_PROG) $(TEST_SRC) -L. -lftprintf

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	@echo "Removing everything but source files"
	$(RM) $(LIB_OBJS) $(TEST_PROG) $(TEST_PROG).o

fclean: clean
	$(RM) $(NAME)

allc: all clean
	@echo "Making all and cleaning up"

re: fclean all
	@echo "Cleaning up and redoing all"

.PHONY: all clean fclean re
