NAME		= ft_container

SRCS		= main.cpp\
			
OBJS		= $(SRCS:.cpp=.o)

RM			= rm -f
CXX			= clang++
CXXFLAGS	= -Wall -Wextra -Werror -std=c++98

$(NAME) : $(OBJS)
	$(CXX) $(CXXFLAGS) -I . $(OBJS) -o $(NAME)

all : $(NAME)

fclean : clean
	$(RM) $(NAME)

clean :
	$(RM) $(OBJS)

re : fclean all