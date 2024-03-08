CC := gcc
SRC_DIR := ./src
INC_DIR := ./inc
LIB_DIR := ./lib
OBJ_DIR := ./build

CFLAGS := -Wall -Wextra -Werror -I $(INC_DIR)
FILE_FILES := \
ft_isalpha.c ft_isdigit.c ft_isalnum.c ft_isascii.c\
ft_isprint.c ft_strlen.c ft_memset.c ft_bzero.c\
ft_memcpy.c ft_memmove.c ft_strlcpy.c ft_strlcat.c\
ft_toupper.c ft_tolower.c ft_strchr.c ft_strrchr.c\
ft_strncmp.c ft_memchr.c ft_memcmp.c ft_strnstr.c ft_atoi.c\
ft_calloc.c ft_strdup.c\
ft_substr.c ft_strjoin.c ft_strtrim.c ft_split.c\
ft_itoa.c ft_strmapi.c ft_striteri.c ft_putchar_fd.c\
ft_putstr_fd.c ft_putendl_fd.c ft_putnbr_fd.c\
ft_printf.c ft_print_c.c ft_print_d.c\
ft_print_p.c ft_print_s.c\
get_next_line.c get_next_line_utils.c

SRC_FILES := $(addprefix $(SRC_DIR)/, $(FILE_NAMES))
OBJ_FILES := $(patsubst $(SRC_DIR)/%.c, $(OBJ_DIR)/%.o, $(SRC_FILES))

.SILENT:

NAME := $(LIB_DIR)/libft.a

# build object files and archive the static library
all: $(NAME)

# build the library with the required .o files
$(NAME):  $(OBJ_FILES)
	@mkdir -p $(LIB_DIR)
	ar rcs $@ $(OBJ_FILES)
	@echo "🥳 Complete! 🥳"

# build .o files from .c files
$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
	@mkdir -p $(OBJ_DIR)
	$(CC) $(CFLAGS) -c $< -o $@

# remove all .o files
clean:
	rm -rf $(OBJ_DIR)

# remove static library as well as all .o files
fclean: clean
	rm -f $(NAME)

# remove all files, then rebuild the library
re: fclean all

# compile everything 
bonus: $(NAME) clean

.PHONY: all clean fclean re msg
