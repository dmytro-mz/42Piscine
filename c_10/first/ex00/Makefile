COMPILER = cc
FLAGS = -Wall -Wextra -Werror

SOURCE_NAME = ft_display_file.c
OBJECT_NAME = $(SOURCE_NAME:.c=.o)
BINARY_NAME = $(SOURCE_NAME:.c=)

all: ${BINARY_NAME}

%.o: %.c
	${COMPILER} ${FLAGS} -c $< -o $@

${BINARY_NAME}: ${OBJECT_NAME}
	${COMPILER} ${FLAGS} ${OBJECT_NAME} -o ${BINARY_NAME}

clean:
	rm -f ${OBJECT_NAME}

fclean: clean
	rm -f ${BINARY_NAME}

re: fclean all

.PHONY: all clean fclean re
