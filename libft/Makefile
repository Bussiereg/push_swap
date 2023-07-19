# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: gbussier <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/12/01 10:37:39 by gbussier          #+#    #+#              #
#    Updated: 2022/12/19 16:52:44 by gbussier         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME := libft.a
SRCS_FILES := ft_isalpha ft_isdigit ft_isalnum ft_isascii ft_isprint ft_strlen ft_memset ft_bzero ft_memcpy ft_memcmp ft_memmove ft_memchr ft_strlcpy ft_strlcat ft_atoi ft_strdup ft_calloc ft_strncmp ft_toupper ft_tolower ft_strchr ft_strrchr ft_strnstr ft_itoa ft_putchar_fd ft_putstr_fd ft_putnbr_fd ft_putendl_fd ft_split ft_substr ft_strjoin ft_strtrim ft_strmapi ft_striteri ft_lstnew_bonus ft_lstadd_front_bonus ft_lstsize_bonus ft_lstlast_bonus ft_lstadd_back_bonus ft_lstdelone_bonus ft_lstclear_bonus ft_lstiter_bonus ft_lstmap_bonus ft_printf pf_put_u pf_put_x pf_put_xmaj pf_put_char pf_put_str pf_put_nbr pf_put_ptr get_next_line_utils get_next_line
SRCS := $(addsuffix .c, $(SRCS_FILES))
OBJS := $(addsuffix .o, $(SRCS_FILES))

CC := gcc
CFLAGS := -Wall -Wextra -Werror

RM := rm -f

all: $(NAME)

$(NAME): $(OBJS)
	@ar rcs $(NAME) $(OBJS)
	@echo "Processus completion: 100%"

%.o: %.c
	@$(CC) $(CFLAGS) -c $<
	@echo "Created $@"

clean:
	@$(RM) $(OBJS)

fclean: clean
	@$(RM) $(NAME)

re: 
	$(MAKE) fclean
	$(MAKE) all
	
.PHONY: clean fclean re
