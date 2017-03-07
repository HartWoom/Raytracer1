##
## Makefile for raytracer in /home/antoine.hartwig/Epitech/Infographie/bsraytracer1
## 
## Made by Antoine Hartwig
## Login   <antoine.hartwig@epitech.net>
## 
## Started on  Thu Feb 23 16:06:18 2017 Antoine Hartwig
## Last update Tue Mar  7 17:41:52 2017 HartWoom
##

SRC	=	main.c			\
		my_put_pixel.c		\
		my_framebuffer_create.c	\
		my_framebuffer_destroy.c\
		src/calc_dir_vector.c	\
		src/plane.c		\
		src/sphere.c

OBJ	=	$(SRC:.c=.o)

CC	=	gcc

LDLIBS	=	-lc_graph_prog -lm

CFLAGS	=	-Iinclude/ -W -Wall -Wextra -pedantic

NAME	=	raytracer

RM	=	rm -rf

all:	$(NAME)

$(NAME):	$(OBJ)
	$(CC) -o $(NAME) $(CFLAGS) $(OBJ) $(LDLIBS)

clean:
	$(RM) $(OBJ)

fclean:	clean
	$(RM) $(NAME)

re:	fclean all

.PHONY:	all clean fclean re
