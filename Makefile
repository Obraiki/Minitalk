# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: obraiki <obraiki@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/01/07 18:47:27 by obraiki           #+#    #+#              #
#    Updated: 2022/01/08 11:10:56 by obraiki          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME1 = server

NAME2 = client

NAME3 = server_bonus.c

NAME4 = client_bonus.c

CC = gcc

INC = minitalk.h

INCB = minitalk_bonus.h

CFLAGS = -Wall -Wextra -Werror

SOURCES =	minitalk_utils.c\

SRCB    =	minitalk_bonus_utils.c\

OBJB    = $(SRCB:.c=.o)

OBJECTS = $(SOURCES:.c=.o)

all:$(NAME1) $(NAME2)

$(NAME1) : server.c $(INC)
	 		$(CC) $(CFLAGS) server.c $(SOURCES) -o server
$(NAME2) : client.c $(INC)
			$(CC) $(CFLAGS) client.c $(SOURCES) -o client

clean:
	rm -rf *.o

fclean: clean
	rm -rf $(NAME1) $(NAME2)
	
bonus: $(NAME4) $(NAME4)
			$(CC) $(CFLAGS) server_bonus.c $(SRCB) -o server
			$(CC) $(CFLAGS) client_bonus.c $(SRCB) -o client	

re: fclean all
