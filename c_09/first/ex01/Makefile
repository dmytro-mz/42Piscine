COMPILER = cc
FLAGS = -Wall -Wextra -Werror -c

LIB = libft.a
SRC_FILES = ft_putchar.c ft_swap.c ft_putstr.c ft_strlen.c ft_strcmp.c

SRC_DIR = ./srcs
INCLUDES_DIR = ./includes

SRCS = $(addprefix ${SRC_DIR}/, ${SRC_FILES})
OBJECTS = $(SRCS:%.c=%.o)

all: ${LIB}

%.o: %.c
	${COMPILER} ${FLAGS} $< -o $@ -I${INCLUDES_DIR}

${LIB}: ${OBJECTS}
	ar rcs ${LIB} ${OBJECTS}

clean:
	rm -f ${OBJECTS}

fclean: clean
	rm -f ${LIB}

re: fclean all

.PHONY: all clean fclean re
