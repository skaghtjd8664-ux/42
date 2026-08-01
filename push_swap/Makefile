# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: honam <honam@student.42.fr>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2026/07/08 16:48:29 by dosong            #+#    #+#              #
#    Updated: 2026/08/01 12:11:05 by honam            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap
CC = cc
CFLAGS = -Wall -Wextra -Werror
RM = rm -f

LIBFT_DIR = ./libft
LIBFT = $(LIBFT_DIR)/libft.a
INCLUDES = -I$(LIBFT_DIR) -I.

SRCS = srcs/push_swap.c srcs/parse.c srcs/sort_utils.c \
	   srcs/sort_simple.c srcs/sort_simple_utils.c \
	   srcs/sort_rank_utils.c srcs/sort_medium.c srcs/sort_complex.c \
	   srcs/utils.c srcs/create_stack.c srcs/check_arg.c \
	   srcs/op_swap.c srcs/op_push.c srcs/op_rotate.c \
	   srcs/op_reverse_rotate.c
OBJS = $(SRCS:.c=.o)

all: $(NAME)

$(NAME): $(OBJS) $(LIBFT)
	$(CC) $(CFLAGS) $(OBJS) $(LIBFT) -o $(NAME)

$(LIBFT):
	make -C $(LIBFT_DIR)

%.o: %.c
	$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

clean:
	make -C $(LIBFT_DIR) clean
	$(RM) $(OBJS)
fclean: clean
	make -C $(LIBFT_DIR) fclean
	$(RM) $(NAME)
re: fclean clean all

.PHONY: all clean fclean re
