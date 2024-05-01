CC=cc
FLAGS=-Wall -Werror -Wextra
EXT_PATHS=-I ./include/ -L ./lib/ -lft

NAME=push_swap

SRCS=push_swap.c ab_utils.c r_utils.c rr_utils.c mxi_atoi.c \
		data_utils.c data2_utils.c data3_utils.c data4_utils.c \

OBJS= $(SRCS:.c=.o)

all: $(NAME)

$(NAME): $(OBJS)
		$(CC) $(FLAGS) -o $(NAME) $(OBJS) $(EXT_PATHS)

clean:
		rm -rf $(OBJS)

fclean: clean
		rm -rf $(NAME)

re : fclean all

.PHONY: all clean fclean re
