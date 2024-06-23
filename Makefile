CC = cc
CFLAGS = -Wall -Wextra -Werror
RM = rm -rf
AR = ar rcs
NAME = libftprintf.a
LIBFT		=		libft

SOURCES	= ft_printf.c print_char.c print_string.c print_percent.c print_digit.c print_hexadecimal.c print_unsigned.c print_pointer.c
OBJECTS		=		$(SOURCES:.c=.o)

TEST_PROG = test_ftprintf
TEST_SRC = test_ftprintf.c

all: $(NAME) $(TEST_PROG)

allc: all clean
	@echo "Making all and cleaning up"

${NAME}: ${OBJECTS}
	make -C $(LIBFT)
	cp libft/libft.a ./
	mv libft.a $(NAME)
	${AR} ${NAME} ${OBJECTS}

$(TEST_PROG): $(TEST_SRC) $(NAME)
	$(CC) $(CFLAGS) -o $(TEST_PROG) $(TEST_SRC) -L. -lftprintf
	@echo "Creating test program"

.c.o:
	${CC} ${FLAGS} -c $< -o $@

clean:
	make clean -C $(LIBFT)
	${RM} ${OBJECTS}
	@echo "Removing everything but library and source files"

fclean: clean
	make fclean -C $(LIBFT)
	${RM} ${NAME}

re: fclean all clean
	make clean -C $(LIBFT)
	@echo "Cleaning up and redoing all"

lib:
	make -C $(LIBFT)
	cp libft/libft.a ./
	mv libft.a $(NAME)

.PHONY: all clean fclean re allc lib
