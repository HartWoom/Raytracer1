/*
** calc_dir_vector.c for raytracer in /home/antoine.hartwig/Epitech/Infographie/bsraytracer1
** 
** Made by Antoine Hartwig
** Login   <antoine.hartwig@epitech.net>
** 
** Started on  Fri Feb 24 16:46:43 2017 Antoine Hartwig
** Last update Fri Feb 24 19:59:12 2017 Antoine Hartwig
*/

#include "include/my.h"

sfVector3f	calc_dir_vector(sfVector2i screen_size, sfVector2i screen_pos)
{
  sfVector3f	dir_vector;

  dir_vector.x = (screen_size.x / 2) - screen_pos.x;
  dir_vector.y = (screen_size.y / 2) - screen_pos.y;
  dir_vector.z = 500;
  return (dir_vector);
}
