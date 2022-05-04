# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: bkhatib <bkhatib@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/05/04 16:31:01 by bkhatib           #+#    #+#              #
#    Updated: 2022/05/04 16:37:14 by bkhatib          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SERVER = server
CLIENT = client
CC = gcc
FLAGS = -Wall -Werror -Wextra

all : $(SERVER) $(CLIENT)

$(SERVER) : 
	@$(CC) $(FLAGS) server.c utils.c -o $(SERVER)
	
$(CLIENT):
	@$(CC) $(FLAGS) client.c utils.c -o $(CLIENT)

bonus : fclean all

clean :
	@rm -f $(SERVER) $(CLIENT)
	
fclean : clean