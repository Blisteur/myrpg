##
## EPITECH PROJECT, 2021
## makefile
## File description:
## makefile
##

CFLAGS = -Wall -Wextra -I include/

LDFLAGS = -L lib -lmy -lcsfml-graphics -lcsfml-system -lcsfml-audio -lcsfml-window

SRC	=	$(wildcard src/*.c) \
		$(wildcard src/game/*.c) \
		$(wildcard src/init/*.c) \
		$(wildcard src/menu/*.c) \
		$(wildcard src/settings/*.c) \
		$(wildcard src/audio/*.c) \
		$(wildcard src/clock/*.c) \
		$(wildcard src/linked_list/*.c) \
		$(wildcard src/intro/*.c) \
		$(wildcard src/mob/*.c) \

OBJ	=	$(SRC:.c=.o)

NAME	=	my_rpg

all:
	$(MAKE) -C lib/my/
	$(MAKE) $(NAME)

$(NAME):	$(OBJ)
	$(CC) -o $(NAME) $(OBJ) $(LDFLAGS)

debug: CFLAGS += -g

debug:	$(OBJ)
	$(MAKE) -C lib/my/
	$(CC) -o $(NAME) $(OBJ) $(LDFLAGS)

clean:
	find -name "*.o" -delete
	find -name "vgcore.*" -delete
	$(MAKE) -C lib/my/ clean

fclean:	clean
	rm -f $(NAME)
	$(MAKE) -C lib/my/ fclean

re: fclean all

re_debug: fclean debug

.PHONY: all debug clean fclean re re_debug