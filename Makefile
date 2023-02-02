# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: hdagdagu <hdagdagu@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/01/14 08:57:38 by hdagdagu          #+#    #+#              #
#    Updated: 2023/02/02 20:25:45 by hdagdagu         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRC =	main.c \
		another_sort.c \
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


SRCBNS = 	bonus/main_bonus.c \
			get_next_line/get_next_line.c \
			bonus/rules_sa_bonus.c \
			bonus/rules_ss_rr_bonus.c \
			bonus/rules_sb_bonus.c \
			bonus/check_bonus.c \

CC = gcc
FLAGS = -Wall -Werror -Wextra

OBJ = $(SRC:.c=.o)
OBJB = $(SRCBNS:.c=.o)

NAME = push_swap
NAMEB = checker

LIBFT = libft
FT_PRINTF = ft_printf

color =\033[0;35m
END=\033[0m

$(NAME) : $(OBJ)
	@make -C $(LIBFT)
	@make -C $(FT_PRINTF)
	@$(CC) $(OBJ) $(FLAGS) libft/libft.a ft_printf/libftprintf.a -o $(NAME)
	@echo "$(color) [✅] Push_swap $(END)"


$(NAMEB) : $(OBJB)
	@make -C $(LIBFT)
	@make -C $(FT_PRINTF)
	@$(CC) $(OBJB) $(FLAGS) libft/libft.a ft_printf/libftprintf.a -o $(NAMEB)
	@echo "$(color) [✅] Push_swap_bonus $(END)"

%.o:%.c
	$(CC) $(FLAGS) -c $^ -o $@

all : $(NAME)

bonus : $(NAMEB)

fclean:
	@make fclean -C $(LIBFT)
	@make fclean -C $(FT_PRINTF)
	@rm -rf $(NAME) $(OBJ) $(OBJB) $(NAMEB)

clean:
	@make clean -C $(LIBFT)
	@make clean -C $(FT_PRINTF)
	@rm -rf $(OBJ) $(OBJB)

re:fclean all 