/*
** plane.c for raytracer in /home/hartwoom/Epitech/Infographie/raytracer1/src
** 
** Made by HartWoom
** Login   <antoine.hartwig@epitech.eu>
** 
** Started on  Tue Mar  7 17:20:24 2017 HartWoom
** Last update Wed Mar  8 17:53:04 2017 HartWoom
*/

#include "../include/my.h"

float   intersect_plane(sfVector3f eyes, sfVector3f dir_v)
{
  float f = 0;

  if (dir_v.z != 0)
    f = -eyes.z / dir_v.z;
  return (f);
}

/* sfVector3f	get_normal_plane(int upward) */
/* { */
/*   sfVector3f	to_return = {0, 0, 0}; */

/*   return (to_return); */
/* } */
