NAME = computor
SOURCES = mandatory/main.cpp mandatory/polynomial.cpp mandatory/complex.cpp
BSOURCES =
OBJECTS = $(SOURCES:.cpp=.o)
BOBJECTS = $(BSOURCES:.cpp=.o)
INCLUDES = mandatory
BINCLUDES = bonus

CC = g++
CFLAGS = -Wall -Wextra -Werror -g

all: $(NAME)

$(NAME): $(OBJECTS)
	$(CC) $(CFLAGS) -o $(NAME) $? -I $(INCLUDES)

bonus: $(OBJECTS) $(BOBJECTS)
	$(AR) -r $(NAME) $?

%.o: %.cpp
	$(CC) -c $(CFLAGS) $? -o $@ -I $(INCLUDES)

clean:
	rm -f $(OBJECTS) $(BOBJECTS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all bonus clean fclean re