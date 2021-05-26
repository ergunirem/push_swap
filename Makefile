# **************************************************************************** #
#                                                                              #
#                                                         ::::::::             #
#    Makefile                                           :+:    :+:             #
#                                                      +:+                     #
#    By: icikrikc <icikrikc@student.codam.nl>         +#+                      #
#                                                    +#+                       #
#    Created: 2021/02/10 14:12:56 by icikrikc      #+#    #+#                  #
#    Updated: 2021/05/26 11:45:23 by icikrikc      ########   odam.nl          #
#                                                                              #
# **************************************************************************** #

GREEN = \033[38;5;2m
NORMAL = \033[38;5;255m
RED = \033[38;5;1m
BLUE = \033[38;5;4m

SRCS	=	main.c input_check.c sort.c \
			swap.c push.c rotate.c rev_rotate.c \
			helper.c\

OBJS	= $(SRCS:.c=.o)

NAME	= push_swap

GCC		= gcc

FLAGS	= -Wall -Wextra -Werror -fsanitize=address -g

HEADER_FILE = cub3d.h

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

.PHONY:	clean fclean re bonus
