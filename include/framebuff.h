/*
** framebuff.h for graph prog in /home/antoine.hartwig/Wireframe
** 
** Made by Antoine Hartwig
** Login   <antoine.hartwig@epitech.net>
** 
** Started on  Wed Nov  9 10:20:53 2016 Antoine Hartwig
** Last update Mon Mar  6 12:56:41 2017 HartWoom
*/

#ifndef S_LIST_
# define S_LIST_

typedef struct	s_my_framebuffer
{
  sfUint8*	pixels;
  int  		width;
  int		height;
}		t_my_framebuffer;

t_my_framebuffer* my_framebuffer_create(int width, int height);

#endif
