# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: bebrandt <benoit.brandt@proton.me>         +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/10/10 17:15:49 by bebrandt          #+#    #+#              #
#    Updated: 2024/01/12 21:39:43 by bebrandt         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	=	libft.a

SRCS	=	ft_atoi.c ft_isalnum.c ft_isalpha.c ft_isascii.c ft_isdigit.c \
			ft_isprint.c ft_strchr.c ft_strlcpy.c ft_strlen.c ft_strncmp.c \
			ft_strnstr.c ft_strrchr.c ft_tolower.c ft_toupper.c ft_strlcat.c \
			ft_memset.c ft_memcpy.c ft_memmove.c ft_memcmp.c ft_memchr.c \
			ft_bzero.c ft_strdup.c ft_calloc.c ft_substr.c ft_strjoin.c \
			ft_strtrim.c ft_split.c ft_itoa.c ft_itoa_hex.c ft_itoa_uint.c \
			ft_strmapi.c ft_striteri.c ft_putchar_fd.c ft_putstr_fd.c \
			ft_putnbr_hex_fd.c ft_putnbr_uint_fd.c ft_putendl_fd.c ft_putnbr_fd.c \
			ft_get_next_line.c ft_get_next_line_utils.c \
			ft_lstnew.c ft_lstadd_front.c ft_lstsize.c ft_lstlast.c \
			ft_lstadd_back.c ft_lstdelone.c ft_lstclear.c ft_lstiter.c ft_lstmap.c \
			ft_atoli.c \
			ft_printf.c flag_utils.c ft_is_specifier.c \
			ft_print_char.c ft_print_str.c ft_print_int.c ft_print_uint.c \
			ft_print_arg.c ft_print_hex.c ft_print_ptr.c ft_print_percent.c \
			ft_print_decimal.c ft_print_width_fd.c ft_print_precision_fd.c \
			ft_print_hex_format.c set_lst.c

OBJS		:=	$(SRCS:.c=.o)

HDRS		=	-I .

CC			=	gcc $(HDRS)

CFLAGS		=	-Wall -Wextra -Werror

AR			=	ar rcs

RM			=	rm -f

all:	$(NAME)

%.o:	%.c
	$(CC) $(CFLAGS) -c $< -o $@

$(NAME):	$(OBJS)
	$(AR) $(NAME) $^

clean:
	$(RM) $(OBJS)

fclean:	clean
	$(RM) $(NAME)

re:	fclean all

.PHONY: all clean fclean re
