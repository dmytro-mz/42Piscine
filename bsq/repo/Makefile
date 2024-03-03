COMPILER = cc
CFLAGS = -Wall -Wextra -Werror

NAME = bsq

SRC_DIR = srcs
INCLUDE_DIR = includes

SRC = create_arr.c create_arr_from_stdin.c fill_array_from_str.c fill_arr.c main.c math_utils.c print_map.c read_first_line.c str_utils.c fill_map_power.c

SOURCES = $(addprefix ${SRC_DIR}/, ${SRC})
OBJECTS = ${SOURCES:.c=.o}

all: ${NAME}

%.o: %.c
	${COMPILER} ${CFLAGS} -c $< -o $@ -I${INCLUDE_DIR}

${NAME}: ${OBJECTS}
	${COMPILER} ${CFLAGS} -o $@ ${OBJECTS}

clean:
	rm -f ${OBJECTS}

fclean: clean
	rm -f ${NAME}

re: fclean all
