SERVERNAME = server
CLIENTNAME = client
CC = cc
CFLAGS = -Wall -Werror -Wextra
LIBFT = ./libft/libft.a
OBJECTS = $(SOURCES:.c=.o)


all: minitalk

minitalk: $(OBJECTS) dependecies
	$(CC) $(CFLAGS) client.c $(LIBFT) -o $(CLIENTNAME)
	$(CC) $(CFLAGS) server.c $(LIBFT) -o $(SERVERNAME)

dependecies:
	cd libft && $(MAKE)

clean:
	rm $(CLIENTNAME) $(SERVERNAME)
