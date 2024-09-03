NAME = gnl.a

CFLAGS = -Wall -Wextra -Werror
SRC_DIR = srcs
OBJ_DIR = obj

# ------------------------------------------------------------------------------------

_SRCS = get_next_line.c get_next_line_utils.c
_BSRCS = get_next_line_bonus.c get_next_line_utils_bonus.c
SRCS = $(addprefix $(SRC_DIR)/, $(_SRCS))
BSRCS = $(addprefix $(SRC_DIR)/, $(_BSRCS))

_OBJ = $(_SRCS:.c=.o)
_BOBJ = $(_BSRCS:.c=.o)
OBJ = $(patsubst %,$(OBJ_DIR)/%,$(_OBJ))
BOBJ = $(patsubst %,$(OBJ_DIR)/%,$(_BOBJ))

# ------------------------------------------------------------------------------------

all:	$(NAME)

$(OBJ_DIR):
	mkdir -p $(OBJ_DIR)

$(NAME): $(OBJ_DIR) $(OBJ)
	ar rcs $(NAME) $(OBJ)

bonus:	fclean $(OBJ_DIR) $(BOBJ)
	ar rcs $(NAME) $(BOBJ)

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
	cc $(CFLAGS) -c $< -o $@

fclean: clean
	rm -rf $(NAME)

clean:
	rm -rf $(OBJ_DIR)

re: fclean all

.PHONY: all bonus fclean clean re