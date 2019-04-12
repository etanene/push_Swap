# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: afalmer- <afalmer-@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/04/10 17:33:31 by afalmer-          #+#    #+#              #
#    Updated: 2019/04/12 19:48:17 by afalmer-         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CHECKER = ./checker
SRCDIR_CHECKER = checkerdir/
SRC_CHECKER = main.c stack.c operations.c
OBJDIR_CHECKER = checkerdir/obj/
OBJ_CHECKER = $(addprefix $(OBJDIR_CHECKER), $(SRC_CHECKER:%.c=%.o))

LIB = libft/libft.a
FLAGS = -Wall -Wextra -Werror

all: $(CHECKER)

$(CHECKER): $(LIB) $(OBJDIR_CHECKER) $(OBJ_CHECKER)
	gcc $(FLAGS) $(OBJ_CHECKER) -L./libft -lft -o $(CHECKER)

$(OBJDIR_CHECKER):
	mkdir checkerdir/obj/

$(OBJDIR_CHECKER)%.o: $(SRCDIR_CHECKER)%.c
	gcc $(FLAGS) -c $< -o $@ -I . -I ./libft/includes/

$(LIB):
	make -C libft/

clean:
	make clean -C libft/
	rm -rf $(OBJDIR_CHECKER)

fclean: clean
	make fclean -C libft/
	rm -rf $(CHECKER)

re: fclean all