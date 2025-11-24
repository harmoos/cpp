CXX			= c++
CXXFLAGS 	= -Wall -Werror -Wextra -std=c++98
NAME		= identify

SRC			= main.cpp \
			  Base.cpp
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
