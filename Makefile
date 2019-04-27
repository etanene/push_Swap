# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: afalmer- <afalmer-@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/04/10 17:33:31 by afalmer-          #+#    #+#              #
#    Updated: 2019/04/27 17:00:51 by afalmer-         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CHECKER = ./checker
SRC_CHECKER = checker.c
OBJ_CHECKER = $(addprefix $(OBJDIR), $(SRC_CHECKER:%.c=%.o))

PUSH_SWAP = ./push_swap
SRC_PUSH_SWAP = push_swap.c get_median.c qsort.c sort3.c
OBJ_PUSH_SWAP = $(addprefix $(OBJDIR), $(SRC_PUSH_SWAP:%.c=%.o))

SRC = set_stack.c check.c stack.c operations.c shared.c
OBJDIR = obj/
OBJ = $(addprefix $(OBJDIR), $(SRC:%.c=%.o))

LIB = libft/libft.a
FLAGS = -Wall -Wextra -Werror

all: $(CHECKER) $(PUSH_SWAP)

$(CHECKER): $(LIB) $(OBJDIR) $(OBJ_CHECKER) $(OBJ)
	gcc $(FLAGS) $(OBJ_CHECKER) $(OBJ) -L./libft -lft -o $(CHECKER)

$(PUSH_SWAP): $(LIB) $(OBJDIR) $(OBJ_PUSH_SWAP) $(OBJ)
	gcc $(FLAGS) $(OBJ_PUSH_SWAP) $(OBJ) -L./libft -lft -o $(PUSH_SWAP)

$(OBJDIR):
	mkdir obj/

$(OBJDIR)%.o: %.c
	gcc $(FLAGS) -c $< -o $@ -I . -I ./libft/includes/ -g

$(LIB):
	make -C libft/

clean:
	make clean -C libft/
	rm -rf $(OBJDIR)

fclean: clean
	make fclean -C libft/
	rm -rf $(CHECKER)

re: fclean all
