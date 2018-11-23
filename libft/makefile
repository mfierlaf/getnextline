# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mfierlaf <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/10/04 17:52:26 by mfierlaf          #+#    #+#              #
#    Updated: 2018/10/23 17:40:51 by mfierlaf         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a

SRCS = *.c

OBJETS = *.o

HEADERS = *.h

FLAGS = -Wall -Wextra -Werror -c

all: $(NAME)

$(NAME):
	gcc $(FLAGS) $(SRCS)
	ar rc $(NAME) $(OBJETS) $(HEADERS)
	ranlib $(NAME)

clean:
	rm -f $(OBJETS)

fclean: clean
	rm -f $(NAME)

re: fclean all clean
