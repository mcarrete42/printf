# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mcarrete <mcarrete@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/10/20 21:36:15 by mcarrete          #+#    #+#              #
#    Updated: 2020/01/13 19:43:25 by mcarrete         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS = ft_isalnum.c ft_isdigit.c ft_memchr.c	ft_memmove.c ft_strlcat.c ft_strnstr.c \
ft_tolower.c ft_atoi.c ft_isalpha.c ft_isprint.c ft_memcmp.c ft_memset.c \
ft_strlcpy.c ft_toupper.c ft_bzero.c ft_isascii.c ft_memccpy.c ft_memcpy.c \
ft_strchr.c ft_strlen.c ft_strrchr.c ft_strncmp.c ft_calloc.c ft_strdup.c \
ft_substr.c ft_strjoin.c ft_strtrim.c ft_split.c ft_itoa.c ft_strmapi.c ft_putchar_fd.c \
ft_putstr_fd.c ft_putendl_fd.c ft_putnbr_fd.c ft_isspace.c ft_isupper.c ft_islower.c \
ft_strcpy.c ft_strncpy.c ft_strcapitalize.c ft_strcat.c ft_strncat.c \
ft_strstr.c ft_super_atoi.c

SRCS_BONUS = ft_lstnew_bonus.c ft_lstadd_front_bonus.c ft_lstsize_bonus.c ft_lstlast_bonus.c \
ft_lstadd_back_bonus.c ft_lstdelone_bonus.c ft_lstclear_bonus.c ft_lstiter_bonus.c \
ft_lstmap_bonus.c

OBJS =			$(SRCS:.c=.o)

OBJS_BONUS =	$(SRCS_BONUS:.c=.o)

INCLUDES=		./

NAME =			libft.a

CFLAGS = 		-Wall -Wextra -Werror

all:			$(NAME)

$(NAME):		$(OBJS)
				 $(CC) $(CFLAGS) -I$(INCLUDES) -c $(SRCS)
				 ar -rcs $(NAME) $(OBJS)

bonus: 			$(OBJS_BONUS)
				 $(CC) $(CFLAGS) -I$(INCLUDES) -c $(SRCS_BONUS)
				 ar -rcs $(NAME) $(OBJS_BONUS)

clean:
				-@ $(RM) *.o

fclean:			 clean
				-@ $(RM) $(NAME)

re: 			fclean all

.PHONY:			 clean fclean re all bonus
