COMPILER = cc
FLAGS = -Wall -Wextra -Werror

SRC_DIR = srcs
INCLUDES_DIR = includes

SRC = ft_tail.c  main.c  write_utils.c

SOURCES = $(addprefix ${SRC_DIR}/, ${SRC})
OBJECTS = $(SOURCES:.c=.o)
BINARY_NAME = ft_tail

all: ${BINARY_NAME}

%.o: %.c
	${COMPILER} ${FLAGS} -c $< -o $@ -I${INCLUDES_DIR}

${BINARY_NAME}: ${OBJECTS}
	${COMPILER} ${FLAGS} ${OBJECTS} -o ${BINARY_NAME}

clean:
	rm -f ${OBJECTS}

fclean: clean
	rm -f ${BINARY_NAME}

re: fclean all

.PHONY: all clean fclean re
