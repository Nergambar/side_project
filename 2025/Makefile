NAME = exec

SRC = Npcs.cpp who/who.cpp where/where.cpp main.cpp
CC = c++
CCFLAGS = -std=c++98 -Wall -Wextra -Werror -g

all: $(NAME)

$(NAME):
	$(CC) $(CCFLAGS) $(SRC) -o $(NAME)

clean:
	rm -f $(NAME)
re: clean  all

.PHONY: all clean 