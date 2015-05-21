LIB=		dummy
NAME=		libnibbler_$(LIB).so
CC=		g++
CP=		cp
RM=		rm -f

CPPFILES=	display.cpp
OFILES=		$(CPPFILES:.cpp=.o)

INTERFACE_PATH=	../../include

CFLAGS=		-I$(INTERFACE_PATH) -Iinclude -g -Wall -Wextra -fPIC
LDFLAGS=	-shared

all: $(NAME)

$(NAME): $(OFILES)
	$(CC) $(OFILES) $(LDFLAGS) -o $(NAME)

clean:
	$(RM) $(OFILES)

fclean: clean
	$(RM) $(NAME)

re: clean fclean all

%.o: %.cpp
	$(CC) $(CFLAGS) -c $< -o $(@F)

