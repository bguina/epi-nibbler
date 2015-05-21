NAME=	nibbler
CC=	g++
RM=	rm -f

CPPSRC=\
  Direction.cpp\
	Game.cpp\
	main.cpp\
	Map.cpp\
	Snake.cpp

OFILES=	$(CPPSRC:.cpp=.o)

CFLAGS=	-Iinclude -g -Wall -Wextra
LDFLAGS=-rdynamic -ldl

all: $(NAME)

$(NAME): $(OFILES)
	$(CC) $(OFILES) $(LDFLAGS) -o $(NAME)

clean:
	$(RM) $(OFILES)
	$(RM) $(NAME)

re: clean all

%.o: %.cpp
	$(CC) $(CFLAGS) -c $< -o $(@F)

