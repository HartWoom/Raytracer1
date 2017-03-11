/*
** light.c for raytracer in /home/hartwoom/Epitech/Infographie/raytracer1/src
** 
** Made by HartWoom
** Login   <antoine.hartwig@epitech.eu>
** 
** Started on  Tue Mar  7 17:33:58 2017 HartWoom
** Last update Sat Mar 11 14:18:04 2017 HartWoom
*/

#include "../include/my.h"

float	get_light_coef(sfVector3f light, sfVector3f normal)
{
  float	k;

  printf("%f  %f  %f\n", light.x, light.y, light.z);
  k = (normal.x * light.x) + (normal.y * light.y) + (normal.z * light.z);
  if (k < 0)
    return (0);
  if (k > 1)
    return (1);
  return (k);
}
