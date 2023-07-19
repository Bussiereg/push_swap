# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: gbussier <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/12/01 10:37:39 by gbussier          #+#    #+#              #
#    Updated: 2023/01/11 16:50:42 by gbussier         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME := push_swap
NAME_BONUS := checker
SRCS_FILES = main swap push rotate reverse_rotate lst_utils lst_utils2 sort_algo cost_move check_functions
SRCS_FILES_BONUS = checker_bonus instruction_bonus lst_utils_bonus check_functions_bonus execute_bonus
SRCS = $(addsuffix .c, $(SRCS_FILES))
OBJS = $(addsuffix .o, $(SRCS_FILES))
SRCS_BONUS = $(addsuffix .c, $(SRCS_FILES_BONUS))
OBJS_BONUS = $(addsuffix .o, $(SRCS_FILES_BONUS))

CC := gcc
CFLAGS := -Wall -Wextra -Werror

RM := rm -f

all: $(NAME)

$(NAME): $(OBJS)
	@$(MAKE) -C libft
	@cp libft/libft.a .
	@$(CC) $(OBJS) -o $(NAME) -L. -lft
	@echo "Compilation success!"

%.o: %.c
	@$(CC) $(CFLAGS) -c $< 
	@echo "Created $@"

bonus: $(NAME_BONUS)

$(NAME_BONUS): $(OBJS_BONUS)
	@$(MAKE) -C libft
	@cp libft/libft.a .
	@$(CC) $(OBJS_BONUS) -o $(NAME_BONUS) -L. -lft
	@echo "Compilation CHECKER success!"

clean:
	@$(RM) $(OBJS) $(OBJS_BONUS) 
	@$(MAKE) clean -C libft

fclean: clean
	@$(RM) $(NAME) $(NAME_BONUS) libft.a
	@$(MAKE) fclean -C libft

re: 
	$(MAKE) fclean
	$(MAKE) all
	
.PHONY: clean fclean re
