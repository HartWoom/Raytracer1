/*
** calc_dir_vector.c for raytracer in /home/antoine.hartwig/Epitech/Infographie/bsraytracer1
** 
** Made by Antoine Hartwig
** Login   <antoine.hartwig@epitech.net>
** 
** Started on  Fri Feb 24 16:46:43 2017 Antoine Hartwig
** Last update Tue Mar  7 17:40:05 2017 HartWoom
*/

#include "../include/my.h"

sfVector3f	calc_dir_vector(float dist, sfVector2i screen_size, sfVector2i screen_pos)
{
  sfVector3f	dir_vector;

  dir_vector.y = (screen_size.x / 2) - screen_pos.x;
  dir_vector.z = (screen_size.y / 2) - screen_pos.y;
  dir_vector.x = dist;
  return (dir_vector);
}
