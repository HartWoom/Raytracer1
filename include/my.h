/*
** my.h for raytracer in /home/antoine.hartwig/Epitech/Infographie/bsraytracer1/include
** 
** Made by Antoine Hartwig
** Login   <antoine.hartwig@epitech.net>
** 
** Started on  Wed Feb  8 08:15:05 2017 Antoine Hartwig
** Last update Fri Feb 24 20:00:47 2017 Antoine Hartwig
*/

#ifndef MY_H_
# define MY_H_

#include <SFML/Graphics/RenderWindow.h>
#include <SFML/Graphics/Sprite.h>
#include <SFML/Graphics/Texture.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>
#include <math.h>
#include "framebuff.h"

#define WIDTH 840
#define HEIGHT 680

void	my_framebuffer_destroy(t_my_framebuffer *);
void	my_put_pixel(t_my_framebuffer *, int, int, sfColor);
sfVector3f	calc_dir_vector(sfVector2i, sfVector2i);
float   intersect_sphere(sfVector3f, sfVector3f, float);

#endif /* !MY_H_ */
