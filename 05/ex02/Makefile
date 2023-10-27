NAME	=	out
SRCS	=	main.cpp \
			Bureaucrat.cpp \
			AForm.cpp \
			ShrubberyCreationForm.cpp \
			RobotomyRequestForm.cpp \
			PresidentialPardonForm.cpp \

FLAGS	=	-std=c++98 -pedantic -Wall -Wextra -Werror
OBJS	= 	$(SRCS:cpp=o)

all: $(NAME)

$(NAME): $(OBJS)
	clang++ $(FLAGS) -o $(NAME) $(SRCS)

%.o: %.cpp
	clang++ $(FLAGS) -c $< -o $@

clean:
	rm -rf $(OBJS)
	rm -rf *_shrubbery

fclean: clean
	rm -rf $(NAME)

re: fclean all