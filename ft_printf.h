#ifndef LIBFTPRINTF_H
# define LIBFTPRINTF_H

#include <string.h>
#include <stddef.h>
#include "libft/libft.h"
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

int print_char(char c);
int print_string(char *str);
int print_digit(long num);
int print_unsigned(unsigned long num);
int print_hexadecimal(long num, char c);
int print_pointer();
int print_percent(void);
int	ft_printf(const char *format, ...);

#endif

/*
wokring makefile:
SOURCES	= ft_printf.c print_char.c print_string.c print_percent.c print_digit.c

OBJECTS		=		$(SOURCES:.c=.o)
LIBFT		=		libft
FLAGS		=		-Wall -Wextra -Werror -g
NAME		=		libftprintf.a
RM			=		rm -f
CC			=		cc
AR			=		ar rcs
TEST_PROG = test_ftprintf
TEST_SRC = test_ftprintf.c

all: $(NAME) $(TEST_PROG)

allc: all clean

${NAME}: ${OBJECTS}
	make -C $(LIBFT)
	cp libft/libft.a ./
	mv libft.a $(NAME)
	${AR} ${NAME} ${OBJECTS}
	echo ${OBJECTS}

$(TEST_PROG): $(TEST_SRC) $(NAME)
	$(CC) $(CFLAGS) -o $(TEST_PROG) $(TEST_SRC) -L. -lftprintf
	@echo "Creating and running test program file"

.c.o:
	${CC} ${FLAGS} -c $< -o $@

clean:
	make clean -C $(LIBFT)
	${RM} ${OBJECTS}

fclean: clean
	make fclean -C $(LIBFT)
	${RM} ${NAME}

re: fclean all clean
	make clean -C $(LIBFT)

lib:
	make -C $(LIBFT)
	cp libft/libft.a ./
	mv libft.a $(NAME)

.PHONY: all clean fclean re
*/
