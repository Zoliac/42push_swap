NAME = push_swap

CC = cc
CFLAGS = -Wall -Wextra -Werror -Iinclude

SRC_DIR = src
OBJ_DIR = obj
LIB_DIR = src/libft

FT = parsing/arrays parsing/checks parsing/stacks parsing/verif_sort \
	rules/push rules/reverse_rot rules/rotate rules/swap \
	sort/chunk_sort sort/chunk_utils sort/get sort/push_swap sort/turk_sort \
	utils/add_on_front utils/cases utils/free_all utils/stack_length \
	main

SOURCES = $(addprefix $(SRC_DIR)/, $(addsuffix .c, $(FT)))
OBJS = $(addprefix $(OBJ_DIR)/, $(addsuffix .o, $(FT)))

LIB = $(LIB_DIR)/libft.a

all: $(NAME)

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
	@mkdir -p $(dir $@)
	$(CC) $(CFLAGS) -c $< -o $@

$(NAME): $(OBJS) $(LIB)
	$(CC) $(CFLAGS) -o $(NAME) $(OBJS) $(LIB)

$(LIB):
	@$(MAKE) -C $(LIB_DIR)

clean:
	@$(MAKE) clean -C $(LIB_DIR)
	rm -rf $(OBJ_DIR)

fclean: clean
	@$(MAKE) fclean -C $(LIB_DIR)
	rm -f $(NAME)


re: fclean all

.PHONY: all clean fclean re bonus