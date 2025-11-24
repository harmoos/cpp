# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: nleoni <nleoni@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/03/27 21:58:24 by nleoni            #+#    #+#              #
#    Updated: 2025/03/27 22:09:43 by nleoni           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


CXX			= c++
CXXFLAGS 	= -Wall -Werror -Wextra -std=c++98
NAME		= megaphone

SRC			= megaphone.cpp
OBJ			= $(SRC:.cpp=.o)

all: 		$(NAME)

$(NAME): 	$(OBJ)
			$(CXX) $(CXXFLAGS) $(OBJ) -o $(NAME)

%.o: %.cpp
			$(CXX) $(CXXFLAGS) -c $< -o $@

clean: 
			rm -f $(OBJ)

fclean: clean
			rm -f $(NAME)

re: 		fclean all

.PHONY: 	all clean fclean re
