NAME = push_swap

CC = cc
CFLAGS = -Wall -Wextra -Werror -Iinclude

SRC_DIR = src
OBJ_DIR = obj
LIB_DIR = src/libft

SRCS = parsing/arrays parsing/checks parsing/handle_args parsing/stacks parsing/verif_sort
	rules/push rules/reverse_rot rules/rotate rules/swap
	sort/push_swap
	utils/all_free utils/chunk_utils utils/listaddfront
	main

SOURCES = $(addprefix $(SRC_DIR)/, $(addsuffix .c, $(FT)))