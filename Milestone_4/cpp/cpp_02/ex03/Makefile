# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: yoherfan <yoherfan@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/09/09 10:24:11 by yoherfan          #+#    #+#              #
#    Updated: 2025/10/13 14:26:40 by yoherfan         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = bsp

CC = c++

CFLAGS = -Wall -Werror -Wextra -g -std=c++98

SRCS = bsp.cpp main.cpp Fixed.cpp Point.cpp

OBJS = $(SRCS:.cpp=.o)

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $(NAME)

%.o: %.cpp
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
