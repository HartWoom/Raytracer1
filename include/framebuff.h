/*
** framebuff.h for graph prog in /home/antoine.hartwig/Wireframe
** 
** Made by Antoine Hartwig
** Login   <antoine.hartwig@epitech.net>
** 
** Started on  Wed Nov  9 10:20:53 2016 Antoine Hartwig
** Last update Thu Feb 23 16:32:16 2017 Antoine Hartwig
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

#endif /* !S_LIST_ */
