# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mcarrete <mcarrete@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/12/29 23:29:42 by mcarrete          #+#    #+#              #
#    Updated: 2019/12/30 23:31:44 by mcarrete         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# NAME			= libftprintf.a
# SRC				= libftprintf.c ft_putdouble.c ft_puthex.c
# SRC_LIB_PATH	= ./libft
# SRC_LIB_NAME	= ft_putchar_fd.c ft_putstr_fd.c ft_putnbr_fd.c
# SRC_LIB			= $(addprefix $(SRC_LIB_PATH)/,$(SRC_LIB_NAME))
# OBJ				= $(SRC:.c=.o)
# OBJ_LIB 		= $(SRC_LIB_NAME:.c=.o)
# CFLAG			= -Wall -Wextra -Werror
# CC				= gcc
# INCLUDES		= ./
# INCLUDES_LIB	= ./libft

# all: $(NAME)

# $(NAME):	$(OBJ) $(OBJ_LIB)
# 	ar -rcs $(NAME) $(OBJ) $(OBJ_LIB)

# %.o: %.c
# 	$(CC) -c $(CFLAGS) -o $@ $< -I $(INCLUDES)

# %.o: $(SRC_LIB_PATH)/%.c
# 	$(CC) -c $(CFLAGS) -o $@ $< -I $(INCLUDES_LIB)

# clean:
# 	rm -f *.o

# fclean: clean
# 	rm -f $(NAME)

# re: 		fclean all

# .PHONY:		clean fclean

NAME			= libftprintf.a
SRC				= libftprintf.c ft_putdouble.c ft_puthex.c parser.c
SRC_LIB_PATH	= ./libft
SRC_LIB_NAME	= ft_putchar_fd.c ft_putstr_fd.c ft_putnbr_fd.c ft_strlen.c \
					ft_itoa.c
SRC_LIB			= $(addprefix $(SRC_LIB_PATH)/,$(SRC_LIB_NAME))
OBJ				= $(SRC:.c=.o)
OBJ_LIB 		= $(SRC_LIB_NAME:.c=.o)
CFLAG			= -Wall -Wextra -Werror
CC				= gcc
INCLUDES		= ./
INCLUDES_LIB	= ./libft

all: $(NAME)

$(NAME):	$(OBJ) $(OBJ_LIB)
	gcc -o $(NAME) $(OBJ) $(OBJ_LIB)

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
