NAME	= 	ft_containers

SRC		=	srcs/main.cpp\
#			srcs/contatiners/stack.h\
#			srcs/contatiners/vector.h

CXX		= c++

CPPFLAGS	= -g #-std=c++98 -Wall -Wextra -Werror

OBJ		= $(SRC:.cpp=.o)

$(NAME): $(OBJ) #$(HEADERS)
	$(CXX) $(CPPFLAGS) $(OBJ) -o $(NAME)

all: $(NAME)

clean:
	rm -rf $(OBJ)

fclean: clean
	rm -rf $(NAME)

re: fclean all

.PHONY: all clean fclean