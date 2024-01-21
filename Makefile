# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: bebrandt <benoit.brandt@proton.me>         +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/12/04 11:59:35 by bebrandt          #+#    #+#              #
#    Updated: 2024/01/21 11:27:17 by bebrandt         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	=	mlx_test

MLX_TEST_SRCS	=	main.c

MLX_TEST_OBJS = $(MLX_TEST_SRCS:.c=.o)

MLX_TEST_OBJ = $(addprefix $(OBJ_DIR),$(MLX_TEST_OBJS))

LIBFT_DIR		=	libft/

LIBFT_NAME		=	libft.a

CC			=	gcc

CFLAGS		=	-Wall -Wextra -Werror -g

RM			=	rm -f

OBJ_DIR		=	objs/

UNAME = $(shell uname)

MLX_LIB = $(MLX_DIR)/libmlx.a

ifeq ($(UNAME), Linux)
	INCLUDES = -I/usr/include -Iminilibx-linux
	MLX_DIR = ./minilibx-linux
else
	INCLUDES = -Iminilibx_macos
	MLX_DIR = ./minilibx_macos
endif
 
ifeq ($(shell uname), Linux)
	MLX_FLAGS = -Lmlx -lmlx -L/usr/lib/X11 -lXext -lX11
else
	MLX_FLAGS = -L$(MLX_DIR) -lmlx -framework OpenGL -framework AppKit
endif
 
RED			=	\033[0;31m
GREEN		=	\033[0;32m
NONE		=	\033[0m

all: $(MLX_LIB) $(NAME)
 
$(NAME): $(MLX_TEST_OBJ)
	@make -C $(LIBFT_DIR) --silent
	$(CC) $(CFLAGS) -o $(NAME) $(OBJS) -L$(LIBFT_DIR) -lft $(MLX_FLAGS) -lm $(MLX_TEST_SRCS)
 
$(OBJ_DIR)%.o: %.c
	@mkdir -p $(OBJ_DIR)
	@echo "$(GREEN)##### Creating" [ $@ ] " #####$(NONE)"
	@$(CC) $(CFLAGS) -c -o $@ $< $(INCLUDES)

$(MLX_LIB):
	@make -C $(MLX_DIR)
	
clean:
	@make -C $(LIBFT_DIR) clean  --silent
	@rm -f $(MLX_TEST_OBJ)
	@echo "$(RED)##### Removed object files #####$(NONE)"

fclean: clean
	@make -C $(LIBFT_DIR) fclean  --silent
	@rm -f $(NAME)
	@echo "$(RED)##### Removed binary files #####$(NONE)"

re: fclean all

.PHONY: all clean fclean re
