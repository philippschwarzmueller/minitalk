SERVERNAME = server
CLIENTNAME = client
CC = cc
CFLAGS = -Wall -Werror -Wextra
LIBFT = ./libft/libft.a

SOURCES_SERVER = server.c
SOURCES_CLIENT = client.c
OBJECTS_SERVER = $(SOURCES_SERVER:.c=.o)
OBJECTS_CLIENT = $(SOURCES_CLIENT:.c=.o)


all: minitalk

minitalk: $(OBJECTS_SERVER) $(OBJECTS_CLIENT) dependecies
	$(CC) $(CFLAGS) $(OBJECTS_CLIENT) $(LIBFT) -o $(CLIENTNAME)
	$(CC) $(CFLAGS) $(OBJECTS_SERVER) $(LIBFT) -o $(SERVERNAME)

dependecies:
	cd libft && $(MAKE)

clean:
	rm $(CLIENTNAME) $(SERVERNAME)
