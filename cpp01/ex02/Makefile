# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: nleoni <nleoni@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/03/30 19:52:12 by nleoni            #+#    #+#              #
#    Updated: 2025/03/30 19:52:33 by nleoni           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CXX			= c++
CXXFLAGS 	= -Wall -Werror -Wextra -std=c++98
NAME		= brain

SRC			= main.cpp
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