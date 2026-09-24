NAME		:= this_not_that
SRCS		:= Bureaucrat.cpp main.cpp AForm.cpp PresidentialPardonForm.cpp \
				RobotomyRequestForm.cpp ShrubberyCreationForm.cpp
OBJS		:= $(SRCS:.cpp=.o)
CPP			:= c++
CPPFLAGS	:= -Wall -Wextra -Werror -std=c++98
RM			:= rm -f

all: $(NAME)

$(NAME): $(OBJS)
	$(CPP) $(CPPFLAGS) -o $(NAME) $(OBJS)

%.o: %.cpp
	$(CPP) $(CPPFLAGS) -c $< -o $@

clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re
