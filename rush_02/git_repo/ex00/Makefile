COMPILER = cc
FLAGS = -Wall -Wextra -Werror

SRC_DIR = srcs
INCLUDES_DIR = includes

SOURCE_FILES = free_dict.c get_base_dict.c main.c parse_dict.c utils.c validate_line.c write_num.c get_base_degree_value.c get_key_value_len.c normalize_num.c parse_line.c validate_key.c write_error_utils.c write_utils.c

SOURCES = $(addprefix ${SRC_DIR}/, ${SOURCE_FILES})
OBJECTS = $(SOURCES:.c=.o)
BINARY_NAME = rush-02

all: ${OBJECTS}
	${COMPILER} ${FLAGS} ${OBJECTS} -o ${BINARY_NAME}

%.o: %.c
	${COMPILER} ${FLAGS} -c $< -o $@ -I${INCLUDES_DIR}

clean:
	rm -f ${OBJECTS}

fclean: clean
	rm -f ${BINARY_NAME}

.PHONY: all clean fclean