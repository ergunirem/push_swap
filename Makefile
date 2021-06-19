# **************************************************************************** #
#                                                                              #
#                                                         ::::::::             #
#    Makefile                                           :+:    :+:             #
#                                                      +:+                     #
#    By: icikrikc <icikrikc@student.codam.nl>         +#+                      #
#                                                    +#+                       #
#    Created: 2021/02/10 14:12:56 by icikrikc      #+#    #+#                  #
#    Updated: 2021/06/19 09:57:02 by icikrikc      ########   odam.nl          #
#                                                                              #
# **************************************************************************** #

GREEN = \033[38;5;2m
NORMAL = \033[38;5;255m
RED = \033[38;5;1m
BLUE = \033[38;5;4m

SRCS	=	main.c \
			parse_args.c \
			sort.c \
			sort_mini.c \
			sort_insertion.c \
			sort_simple.c \
			sort_bubble.c \
			helpers_input.c \
			helpers_lst.c \
			helpers_stack.c \
			./operations/swap.c \
			./operations/push.c \
			./operations/rotate.c \
			./operations/rev_rotate.c \
			print_stacks.c \

OBJS	= $(SRCS:.c=.o)

NAME	= push_swap

GCC		= gcc

FLAGS	= -Wall -Wextra -Werror -fsanitize=address -g

HEADER_FILE = push_swap.h

LIBFT_DIR = utils/libft

LIBFT_LIB = libft.a

all:	$(NAME)

$(NAME):	$(OBJS)
	$(MAKE) bonus -C $(LIBFT_DIR)
	$(GCC) $(FLAGS) -o $(NAME) $(OBJS) $(LIBFT_DIR)/$(LIBFT_LIB)

%.o: %.c $(HEADER_FILE)
	@echo "$(GREEN)Compiling:$(NORMAL)"
	$(GCC) -c $< -o $(<:.c=.o)
	@echo "$(GREEN)Successfully compiled!$(NORMAL)"

clean:
	@echo "$(RED)Removing all object files...$(NORMAL)"
	rm -f $(OBJS)
	make -C $(LIBFT_DIR) clean
	@echo "$(GREEN)Succesfully removed all object files!$(NORMAL)"

fclean: clean
	@echo "$(RED)Removing libraries...$(NORMAL)"
	rm -f $(NAME)
	make -C $(LIBFT_DIR) fclean
	@echo "$(GREEN)Successfully removed libraries!$(NORMAL)"

re: fclean all

.PHONY:	clean fclean re
