CC = cc 

PRINTF= ft_printf/libftprintf.a

SERVER = server

CLIENT = client

SRCS = server.c 

SRCC = client.c

OBJS = $(SRCS:.c=.o)

OBJC = $(SRCC:.c=.o)

CFLAGS = -Wall -Wextra -Werror

all: $(SERVER) $(CLIENT)

$(SERVER): $(OBJS)
	make -C ./ft_printf
	$(CC) $(CFLAGS) server.c $(PRINTF) -o server

$(CLIENT): $(OBJC)
	$(CC) $(CFLAGS) client.c $(PRINTF) -o client

clean: 
	make clean -C ./ft_printf
	rm -f $(OBJS) $(OBJC)

fclean: clean
	make fclean -C ./ft_printf
	rm -f $(SERVER) $(CLIENT)

re: fclean all

.PHONY: all clean fclean re
