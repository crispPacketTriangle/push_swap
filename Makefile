CC=cc
#CFLAGS=-Wall -Werror -Wextra
# remember to include the flags when compiling after $(CC) ..
# and remove raylib from EXT_PATHS
# also move rel functions in push_utils.c to data_utils.c
EXT_PATHS=-I ./include/ -L ./lib/ -lft -lraylib -lGL -lX11 -lm
NAME=push_swap

SRCS=push_swap.c ab_utils.c r_utils.c rr_utils.c data_utils.c \
		push_utils.c mxi_atoi.c\

OBJS= $(SRCS:.c=.o)

all: $(NAME)

$(NAME): $(OBJS)
		$(CC) -o $(NAME) $(OBJS) $(EXT_PATHS)

clean:
		rm -rf $(OBJS)

fclean: clean
		rm -rf $(NAME)

re : fclean all

.PHONY: all clean fclean re
