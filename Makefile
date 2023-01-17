NAME = minitalk
SERVERNAME = server
CLIENTNAME = client
CC = cc
CFLAGS = -Wall -Werror -Wextra
LIBFT = ./libft/libft.a

SOURCES_SERVER = server.c
SOURCES_CLIENT = client.c
OBJECTS_SERVER = $(SOURCES_SERVER:.c=.o)
OBJECTS_CLIENT = $(SOURCES_CLIENT:.c=.o)


all: $(NAME) 

$(NAME): $(LIBFT) $(SERVERNAME) $(CLIENTNAME)

$(SERVERNAME): $(OBJECTS_SERVER) $(LIBFT)
	$(CC) $(CFLAGS) $(OBJECTS_SERVER) $(LIBFT) -o $(SERVERNAME)

$(CLIENTNAME): $(OBJECTS_CLIENT) $(LIBFT)
	$(CC) $(CFLAGS) $(OBJECTS_CLIENT) $(LIBFT) -o $(CLIENTNAME)

$(LIBFT):
	git submodule init
	git submodule update
	cd libft && $(MAKE)

clean:
	rm $(CLIENTNAME) $(SERVERNAME)
	cd libft && $(MAKE) clean

fclean: clean
	rm $(OBJECTS_SERVER) $(OBJECTS_CLIENT)
	cd libft && $(MAKE) fclean

re: fclean all

.PHONY: all clean fclean re
