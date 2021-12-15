SRC			= 	main.cpp \
				ClassMaker.cpp

Header		=	ClassMaker.hpp

OBJ			= 	$(SRC:.cpp=.o)
NAME		=	ClassMaker
FLAGS		=	-Wall -Wextra -Werror -std=c++98
CC			=	clang++
RM			=	rm -f

.cpp.o:			
			$(CC) $(FLAGS) -c $< -o $(<:.cpp=.o)


all:		$(NAME) 

$(NAME):	${HEADER} $(OBJ)
				$(CC) $(FLAGS) $(OBJ) -o $(NAME)

clean:			
				$(RM) $(OBJ)

fclean:		clean
				$(RM) $(NAME)

re:			fclean all

.PHONY:		all clean fclean re
