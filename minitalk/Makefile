# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: akaabi <akaabi@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/01/20 18:13:28 by akaabi            #+#    #+#              #
#    Updated: 2023/01/23 23:37:05 by akaabi           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CFLAGS = -Wall -Werror -Wextra
CC = cc
CLIENT = client
SERVER = server
CLIENT_BONUS = client_bonus
SERVER_BONUS = server_bonus


all: $(CLIENT) $(SERVER)

$(CLIENT) : client.c minitalk.h
		$(CC) $(CFLAGS) client.c minitalk_utils.c -o client

$(SERVER) : server.c minitalk.h
		$(CC) $(CFLAGS) server.c minitalk_utils.c -o server

bonus: $(CLIENT_BONUS) $(SERVER_BONUS)

$(CLIENT_BONUS) : client_bonus.c minitalk.h
		$(CC) $(CFLAGS) client_bonus.c minitalk_utils.c -o client_bonus

$(SERVER_BONUS) : server_bonus.c minitalk.h
		$(CC) $(CFLAGS) server_bonus.c minitalk_utils.c -o server_bonus
clean:
		rm -rf $(CLIENT) $(SERVER) $(CLIENT_BONUS) $(SERVER_BONUS)

fclean:
		rm -rf $(CLIENT) $(SERVER) $(CLIENT_BONUS) $(SERVER_BONUS)

re:    fclean all