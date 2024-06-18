NAME = libft.a
CC = gcc
CFLAGS = -Wall -Wextra -Werror -g -I headers/

# Define the base object directory
OBJ_DIR = .obj/

# Source files with directory prefix
LIBFT_SRC = $(addprefix src/libft_src/,ft_isdigit.c ft_isalpha.c ft_isalnum.c ft_isascii.c ft_strlen.c ft_memset.c \
	ft_bzero.c ft_memcpy.c ft_memmove.c ft_isprint.c ft_strlcpy.c ft_strlcat.c ft_toupper.c \
	ft_tolower.c ft_strchr.c ft_strrchr.c ft_strncmp.c ft_memchr.c ft_memcmp.c \
	ft_strnstr.c ft_atoi.c ft_calloc.c ft_strdup.c ft_substr.c ft_strjoin.c \
	ft_strtrim.c ft_split.c ft_itoa.c ft_strmapi.c ft_striteri.c ft_putchar_fd.c \
	ft_putstr_fd.c ft_putendl_fd.c ft_putnbr_fd.c \
	ft_lstnew.c ft_lstadd_front.c ft_lstsize.c ft_lstlast.c ft_lstadd_back.c \
	ft_lstdelone.c ft_lstclear.c ft_lstmap.c ft_lstiter.c)

PRINTF_SRC = $(addprefix src/printf_src/,ft_printf.c ft_printf_str.c ft_printf_binary.c ft_printf_nbr.c)

GET_NEXT_LINE_SRC = $(addprefix src/get_next_line_src/,get_next_line.c get_next_line_utils.c)

PUSH_SWAP_LST_SRC = $(addprefix src/push_swap_helpers_src/lst/, ft_int_lstnew.c \
	ft_int_lstclear.c \
	ft_int_lstadd_back.c \
	ft_int_lstsize.c)

PUSH_SWAP_HELPERS_SRC = $(addprefix src/push_swap_helpers_src/helper/, ft_check_input.c \
	ft_free_split.c \
	ft_is_valid_input.c)

PUSH_SWAP_MOVES_SRC = $(addprefix src/push_swap_helpers_src/moves/, ft_push.c \
	ft_rotate.c \
	ft_reverse_rotate.c \
	ft_swap.c)



# Object files for the library
LIBFT_OBJ = $(LIBFT_SRC:src/libft_src/%.c=$(OBJ_DIR)%.o)
PRINTF_OBJ = $(PRINTF_SRC:src/printf_src/%.c=$(OBJ_DIR)%.o)
GET_NEXT_LINE_OBJ = $(GET_NEXT_LINE_SRC:src/get_next_line_src/%.c=$(OBJ_DIR)%.o)
PUSH_SWAP_LST_OBJ = $(PUSH_SWAP_LST_SRC:src/push_swap_helpers_src/lst/%.c=$(OBJ_DIR)%.o)
PUSH_SWAP_HELPERS_OBJ = $(PUSH_SWAP_HELPERS_SRC:src/push_swap_helpers_src/helper/%.c=$(OBJ_DIR)%.o)
PUSH_SWAP_MOVES_OBJ = $(PUSH_SWAP_MOVES_SRC:src/push_swap_helpers_src/moves/%.c=$(OBJ_DIR)%.o)

# Combine all object files
OBJ = $(LIBFT_OBJ) $(PRINTF_OBJ) $(GET_NEXT_LINE_OBJ) $(PUSH_SWAP_HELPERS_OBJ) $(PUSH_SWAP_LST_OBJ) $(PUSH_SWAP_MOVES_OBJ)

# ANSI escape sequence for red text
RED = \033[0;31m
PINK_FLUO=\033[38;5;201m
GOLD=\033[38;5;220m
COOL_YELLOW=\033[38;2;195;215;0m
# Bold High Intensity
BOLD_INTENSE_BLACK=\033[1;90m
BOLD_INTENSE_RED=\033[1;91m
BOLD_INTENSE_GREEN=\033[1;92m
BOLD_INTENSE_YELLOW=\033[1;93m
BOLD_INTENSE_BLUE=\033[1;94m
BOLD_INTENSE_PURPLE=\033[1;95m
BOLD_INTENSE_CYAN=\033[1;96m
BOLD_INTENSE_WHITE=\033[1;97m

# Background
BACKGROUND_BLACK=\033[40m
BACKGROUND_RED=\033[41m
BACKGROUND_GREEN=\033[42m
BACKGROUND_YELLOW=\033[43m
BACKGROUND_BLUE=\033[44m
BACKGROUND_PURPLE=\033[45m
BACKGROUND_CYAN=\033[46m
BACKGROUND_WHITE=\033[47m
# ANSI escape sequence for no color (reset)

NC = \033[0m


all: $(NAME)

# Rule to make the object files for libft and printf, silenced
$(OBJ_DIR)%.o: src/libft_src/%.c | $(OBJ_DIR)
	@$(CC) $(CFLAGS) -c $< -o $@

$(OBJ_DIR)%.o: src/printf_src/%.c | $(OBJ_DIR)
	@$(CC) $(CFLAGS) -c $< -o $@

$(OBJ_DIR)%.o: src/get_next_line_src/%.c | $(OBJ_DIR)
	@$(CC) $(CFLAGS) -c $< -o $@

$(OBJ_DIR)%.o: src/push_swap_helpers_src/helper/%.c | $(OBJ_DIR)
	@$(CC) $(CFLAGS) -c $< -o $@

$(OBJ_DIR)%.o: src/push_swap_helpers_src/lst/%.c | $(OBJ_DIR)
	@$(CC) $(CFLAGS) -c $< -o $@

$(OBJ_DIR)%.o: src/push_swap_helpers_src/moves/%.c | $(OBJ_DIR)
	@$(CC) $(CFLAGS) -c $< -o $@

# Rule to make the library, only display ASCII art on success
$(NAME): $(OBJ)
	@echo "Creating library $(NAME)"
	@ar rcs $@ $(OBJ)
	@echo "$(COOL_YELLOW)Library $(NAME) created.$(NC)"
	@echo "$$LIBFT_ASCII_ART"
	@sleep 2
	@clear
	@echo "$(COOL_YELLOW)Library $(NAME) created.$(NC)"


$(OBJ_DIR):
	@mkdir -p $(OBJ_DIR)

clean:
	@rm -rf $(OBJ_DIR)*.o

fclean: clean
	@rm -f $(NAME)
	@rm -rf $(OBJ_DIR)

re: fclean all
# ASCII Art for "Libft"
define LIBFT_ASCII_ART
    ___ __    ______
   / (_) /_  / __/ /_
  / / / __ \/ /_/ __/
 / / / /_/ / __/ /_
/_/_/_.___/_/  \__/           _ ___
  _________  ____ ___  ____  (_) (_)___  ____ _
 / ___/ __ \/ __ `__ \/ __ \/ / / / __ \/ __ `/
/ /__/ /_/ / / / / / / /_/ / / / / / / / /_/ /  _ _ _
\___/\____/_/ /_/ /_/ .___/_/_/_/_/ /_/\__, /  (_|_|_)
                   /_/                /____/
endef
export LIBFT_ASCII_ART
