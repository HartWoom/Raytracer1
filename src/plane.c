/*
** plane.c for raytracer in /home/hartwoom/Epitech/Infographie/raytracer1/src
** 
** Made by HartWoom
** Login   <antoine.hartwig@epitech.eu>
** 
** Started on  Tue Mar  7 17:20:24 2017 HartWoom
** Last update Sat Mar 11 14:05:27 2017 HartWoom
*/

#include "../include/my.h"

float   intersect_plane(sfVector3f eyes, sfVector3f dir_v)
{
  float f = 0;

  if (dir_v.z != 0)
    {
      f = -eyes.z / dir_v.z;
      return (f);
    }
  return (-1);
}

sfVector3f	get_normal_plane(int upward)
{
  sfVector3f	to_return;

  to_return.x = 0;
  to_return.y = 0;
  if (upward == 1)
    to_return.z = 100;
  else if (upward == 0)
    to_return.z = -100;
  else
    to_return.z = 0;
  return (to_return);
}
