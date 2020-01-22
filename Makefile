# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mcarrete <mcarrete@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/12/29 23:29:42 by mcarrete          #+#    #+#              #
#    Updated: 2020/01/22 17:38:22 by mcarrete         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME			= libftprintf.a
SRC				= libftprintf.c ft_putdouble.c parser.c flag_parser.c \
					int_output.c hex_output.c float_output.c char_output.c \
					string_output.c main.c
SRC_LIB_PATH	= ./libft
SRC_LIB_NAME	= ft_putchar_fd.c ft_putstr_fd.c ft_putnbr_fd.c ft_strlen.c \
					ft_itoa.c ft_strchr.c ft_atoi.c ft_isdigit.c ft_isspace.c ft_bspace.c \
					ft_strjoin.c ft_bzero.c ft_toupper.c ft_itoa_hex.c ft_islower.c \
					ft_substr.c
SRC_LIB			= $(addprefix $(SRC_LIB_PATH)/$(SRC_LIB_NAME))
OBJ				= $(SRC:.c=.o)
OBJ_LIB 		= $(SRC_LIB_NAME:.c=.o)
CFLAG			= -Wall -Wextra -Werror
CC				= gcc
INCLUDES		= ./
INCLUDES_LIB	= ./libft

all: $(NAME)

$(NAME):	$(OBJ) $(OBJ_LIB)
	ar -rcs $(NAME) $(OBJ) $(OBJ_LIB)

%.o: %.c
	$(CC) -c $(CFLAGS) -o $@ $< -I $(INCLUDES)

%.o: $(SRC_LIB_PATH)/%.c
	$(CC) -c $(CFLAGS) -o $@ $< -I $(INCLUDES_LIB)

clean:
	rm -f *.o

fclean: clean
	rm -f $(NAME)

re: 		fclean all

.PHONY:		clean fclean
