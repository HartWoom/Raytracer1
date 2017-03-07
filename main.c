
/*
** main.c for raytracer in /home/antoine.hartwig/Epitech/Infographie/bsraytracer1
** 
** Made by Antoine Hartwig
** Login   <antoine.hartwig@epitech.net>
** 
** Started on  Thu Feb 23 16:35:40 2017 Antoine Hartwig
** Last update Tue Mar  7 19:18:01 2017 HartWoom
*/

#include "include/my.h"

void	what_to_draw(t_my_framebuffer *framebuffer, sfVector2i pos,
		     float s, float p)
{
  if (s < 0 && p < 0)
    my_put_pixel(framebuffer, pos.x, pos.y, sfBlack);
  if (s >= 0 && p <= 0)
    my_put_pixel(framebuffer, pos.x, pos.y, sfRed);
  if (s > 0 && p > 0)
    {
      if (s >= p)
	my_put_pixel(framebuffer, pos.x, pos.y, sfBlue);
      else if (s < p)
	my_put_pixel(framebuffer, pos.x, pos.y, sfRed);
    }
  if (s < 0 && p > 0)
    my_put_pixel(framebuffer, pos.x, pos.y, sfBlue);
}

void		raytrace_scene(t_my_framebuffer *framebuffer)
{
  sfVector2i	pos = {0, 0};
  sfVector2i	size = {840, 680};
  sfVector3f	eyes = {-200.0, 0.0, 20.0};
  sfVector3f	vect;
  float		s;
  float		p;

  while (pos.x != size.x || pos.y != size.y)
    {
      vect = calc_dir_vector(500, size, pos);
      s = intersect_cylinder(eyes, vect, 30.0);
      p = intersect_plane(eyes, vect);
      what_to_draw(framebuffer, pos, s, p);
      if (pos.x == size.x)
  	{
  	  pos.y++;
  	  pos.x = 0;
  	}
      else
  	pos.x++;
    }
}

int		process_game_loop(sfRenderWindow *window, sfSprite *sprite)
{
  sfEvent	event;

  while (sfRenderWindow_isOpen(window))
    {
      while (sfRenderWindow_pollEvent(window, &event))
        {
	  if (sfKeyboard_isKeyPressed(sfKeyEscape) == 1)
	    sfRenderWindow_close(window);
	  if (event.type == sfEvtClosed)
	    sfRenderWindow_close(window);
        }
      sfRenderWindow_clear(window, sfBlack);
      sfRenderWindow_drawSprite(window, sprite, NULL);
      sfRenderWindow_display(window);
    }
  return (0);
}

int	main()
{
  sfVideoMode		mode = {WIDTH, HEIGHT, 32};
  sfRenderWindow	*window;
  sfTexture		*texture;
  sfSprite		*sprite;
  t_my_framebuffer	*framebuffer;

  window = sfRenderWindow_create(mode, "Bootstrap Raytracer 1",
				 sfResize | sfClose, NULL);
  framebuffer = malloc(sizeof(t_my_framebuffer));
  framebuffer = my_framebuffer_create(WIDTH, HEIGHT);
  sprite = sfSprite_create();
  texture = sfTexture_create(WIDTH, HEIGHT);
  sfSprite_setTexture(sprite, texture, sfTrue);

  raytrace_scene(framebuffer);
  sfTexture_updateFromPixels(texture, framebuffer->pixels,
			     framebuffer->width, framebuffer->height, 0,0);
  process_game_loop(window, sprite);
  my_framebuffer_destroy(framebuffer);
  sfSprite_destroy(sprite);
  sfTexture_destroy(texture);
  sfRenderWindow_destroy(window);
  return (0);
}
