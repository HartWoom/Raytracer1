/*
** intersect_plane.c for raytracer in /home/hartwoom/Epitech/Infographie/raytracer1
** 
** Made by HartWoom
** Login   <antoine.hartwig@epitech.eu>
** 
** Started on  Fri Mar  3 16:43:10 2017 HartWoom
** Last update Fri Mar  3 19:26:46 2017 HartWoom
*/

#include "include/my.h"

float	intersect_plane(sfVector3f eyes, sfVector3f dir_v)
{
  float	f = 0;

  if (dir_v.z != 0)
    f = -eyes.z / dir_v.z;
  return (f);
}
