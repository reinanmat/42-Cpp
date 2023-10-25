NAME = a.out

PATH_INCS = ./
PATH_SRCS = ./
PATH_OBJS = ./objects/

FILES = main Bureaucrat Form
SRCS = ${FILES:%=$(PATH_OBJS)%.cpp}
OBJS = ${FILES:%=$(PATH_OBJS)%.o}

ifeq ($(DEBUG), 1)
	FLAGS = -Wall -Wextra -Werror -std=c++98 -g3 -D DEBUG
else
	FLAGS = -Wall -Wextra -Werror -std=c++98 -g3
endif

all: $(NAME)

$(NAME): $(OBJS)
	c++ $(FLAGS) $(OBJS) -o $(NAME)

$(PATH_OBJS)%.o: $(PATH_SRCS)%.cpp | $(PATH_OBJS)
	c++ $(FLAGS) -c $< -o $@

$(PATH_OBJS):
	mkdir -p $(PATH_OBJS)

clean:
	rm -rf $(PATH_OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

debug: fclean
	@make DEBUG=1 --no-print-directory

.PHONY: all clean fclean re debug
