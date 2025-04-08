CC = cc 

PRINTF= ft_printf/libftprintf.a

SERVER = server

SERVER_BONUS = server_bonus

CLIENT = client

CLIENT_BONUS = client_bonus

SRCS = minitalk/server.c 

SRCC = minitalk/client.c

SRCS_BONUS = minitalk_bonus/server_bonus.c 
SRCC_BONUS = minitalk_bonus/client_bonus.c

OBJS = $(SRCS:.c=.o)

OBJC = $(SRCC:.c=.o)

OBJS_BONUS = $(SRCS_BONUS:.c=.o)
OBJC_BONUS = $(SRCC_BONUS:.c=.o)

CFLAGS = -Wall -Wextra -Werror 

all: $(SERVER) $(CLIENT)

bonus: $(SERVER_BONUS) $(CLIENT_BONUS)

$(PRINTF):
	make -C ./ft_printf

$(SERVER): $(OBJS) $(PRINTF)
	make -C ./ft_printf
	$(CC) $(CFLAGS) $(OBJS) $(PRINTF) -o $(SERVER)

$(CLIENT): $(OBJC) $(PRINTF)
	$(CC) $(CFLAGS) $(OBJC) $(PRINTF) -o $(CLIENT)

$(SERVER_BONUS): $(OBJS_BONUS) $(PRINTF)
	make -C ./ft_printf
	$(CC) $(CFLAGS) $(OBJS_BONUS) $(PRINTF) -o $(SERVER_BONUS)

$(CLIENT_BONUS): $(OBJC_BONUS) $(PRINTF)
	make -C ./ft_printf
	$(CC) $(CFLAGS) $(OBJC_BONUS) $(PRINTF) -o $(CLIENT_BONUS)


clean: 
	make clean -C ./ft_printf
	rm -f $(OBJS) $(OBJC) $(OBJS_BONUS) $(OBJC_BONUS)

fclean: clean
	make fclean -C ./ft_printf
	rm -f $(SERVER) $(CLIENT) $(SERVER_BONUS) $(CLIENT_BONUS)

re: fclean all

.PHONY: all bonus clean fclean re