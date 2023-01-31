# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: hdagdagu <hdagdagu@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/01/14 08:57:38 by hdagdagu          #+#    #+#              #
#    Updated: 2023/01/30 20:46:55 by hdagdagu         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRC =	main.c \
		sort.c \
		check.c \
		best_element.c \
		helpers.c \
		push.c \
		count.c \
		best_score.c \
		rules_sb.c \
		rules_sa.c \
		rules_ss_rr.c \
		print.c \


CC = gcc
FLAGS = -Wall -Werror -Wextra

OBJ = $(SRC:.c=.o)

NAME = push_swap

LIBFT = libft
FT_PRINTF = ft_printf

color =\033[0;35m
END=\033[0m

%.o:%.c
	@$(CC) $(FLAGS) -c $^ $@

all : $(SRC)
	@make -C $(LIBFT)
	@make -C $(FT_PRINTF)
	@$(CC) $(SRC) $(FLAGS) libft/libft.a ft_printf/libftprintf.a -o $(NAME)
	@rm libft/*.o
	@rm ft_printf/*.o
	@echo "$(color) [✅] Push_swap $(END)"

fclean:
	@make fclean -C $(LIBFT)
	@make fclean -C $(FT_PRINTF)
	@rm -rf $(NAME) $(OBJ)

clean:
	@make clean -C $(LIBFT)
	@make clean -C $(FT_PRINTF)
	@rm -rf $(OBJ)

re:fclean all 