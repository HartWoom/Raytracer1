/*
** main.c for raytracer in /home/antoine.hartwig/Epitech/Infographie/bsraytracer1
** 
** Made by Antoine Hartwig
** Login   <antoine.hartwig@epitech.net>
** 
** Started on  Thu Feb 23 16:35:40 2017 Antoine Hartwig
** Last update Thu Mar  2 18:42:24 2017 HartWoom
*/

#include "include/my.h"

void	raytrace_scene(t_my_framebuffer *framebuffer)
{
  sfVector2i	pos = {420, 340};
  sfVector2i	size = {840, 680};
  sfVector3f	eyes = {-200, 0, 0};
  sfVector3f	vect;

  vect = calc_dir_vector(size, pos);
  printf("vect.x: %f vect.y: %f vect.z: %f\n", vect.x, vect.y, vect.z);
  printf("f: %f\n", intersect_sphere(eyes, vect, 50));
  while (pos.x != size.x - 1 || pos.y != size.y - 1)
    {
      if (intersect_sphere(eyes, calc_dir_vector(size, pos), 20) != -1)
  	my_put_pixel(framebuffer, pos.x, pos.y, sfRed);
      if (pos.x == size.x)
  	{
  	  pos.y++;
  	  pos.x = 0;
  	}
      else
  	pos.x++;
    }
}

/*
** This main function is provided for the bootstrap of the Raytracer1.
** YOU MUST NOT SUBMIT IT !
**
** Some functions are required for this code to work :
** - All functions of the c_graph_prog library
** - my_framebuffer_create
** - raytrace_scene
** - my_framebuffer_destroy
**
** //// my_framebuffer_create(int width, int height)
** Creates a framebuffer from the width and the height of the frame.
** 
** //// raytrace_scene(t_my_framebuffer *framebuffer)
** Launches rays and fills the framebuffer with the proper color for 
** every pixels.
** The frame is static so the function only needs to be called once at
** the beginning of the program (as it currently is).
**
** //// my_framebuffer_destroy(t_my_framebuffer *framebuffer)
** Frees the space allocated to the framebuffer.
*/

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
  sfEvent       event;

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
