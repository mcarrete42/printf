# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mcarrete <mcarrete@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/12/16 17:17:38 by mcarrete          #+#    #+#              #
#    Updated: 2019/12/19 21:02:26 by mcarrete         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS = libftprintf.c

OBJS =				$(SRCS:.c=.o)

#OBJS_BONUS =		$(SRCS_BONUS:.c=.o)

INCLUDES =			./

NAME =				libftprintf.a

CFLAGS =			-Wall -Werror -Wextra

CC = 				gcc

all = 				$(NAME)

$(NAME):			$(OBJS)
						$(CC) $(CFLAGS) -I$(INCLUDES) -c $(SRCS)
						ar -rcs $(NAME) $(OBJS)

bonus:				$(OBJS_BONUS)
						$(CC) $(CFLAGS) -I$(INCLUDES) -c $(SRCS_BONUS)
						ar -rcs $(NAME) $(OBJS_BONUS)

clean:
					-@ $(RM) *.o

fclean:				clean
					-@ $(RM) $(NAME)

re:					fclean all

.PHONY:				clean fclean re all bonus

