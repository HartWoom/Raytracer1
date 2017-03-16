##
## Makefile for raytracer in /home/antoine.hartwig/Epitech/Infographie/bsraytracer1
## 
## Made by Antoine Hartwig
## Login   <antoine.hartwig@epitech.net>
## 
## Started on  Thu Feb 23 16:06:18 2017 Antoine Hartwig
## Last update Thu Mar 16 14:33:14 2017 HartWoom
##

SRC	=	main.c			\
		my_put_pixel.c		\
		my_framebuffer_create.c	\
		my_framebuffer_destroy.c\
		src/utils.c		\
		src/calc_dir_vector.c	\
		src/translate.c		\
		src/rotate.c		\
		src/plane.c		\
		src/sphere.c		\
		src/cylinder.c		\
		src/cone.c		\
		src/light.c

OBJ	=	$(SRC:.c=.o)

CC	=	gcc

LDLIBS	=	-lc_graph_prog -lm

CFLAGS	=	-Iinclude -W -Wall -Wextra -pedantic

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
