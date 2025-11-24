# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: nleoni <nleoni@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/03/30 17:59:07 by nleoni            #+#    #+#              #
#    Updated: 2025/04/15 16:54:16 by nleoni           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CXX			= c++
CXXFLAGS 	= -Wall -Werror -Wextra -std=c++98
NAME		= zombie

SRC			= main.cpp \
			  Zombie.cpp \
			  newZombie.cpp \
			  randomChump.cpp
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
