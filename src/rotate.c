/*
** rotate.c for raytracer in /home/hartwoom/Epitech/Infographie/raytracer1/src
** 
** Made by HartWoom
** Login   <antoine.hartwig@epitech.eu>
** 
** Started on  Tue Mar  7 16:59:50 2017 HartWoom
** Last update Thu Mar 16 10:14:50 2017 HartWoom
*/

#include "include/my.h"

sfVector3f	rotate_arround_x(sfVector3f vector, float angle)
{
  vector.y = vector.y * cos(angle) + vector.z * -sin(angle);
  vector.z = vector.y * sin(angle) + vector.z * cos(angle);
  return (vector);
}

sfVector3f	rotate_arround_y(sfVector3f vector, float angle)
{
  vector.x = vector.x * cos(angle) + vector.z * sin(angle);
  vector.z = vector.x * -sin(angle) + vector.z * cos(angle);
  return (vector);
}

sfVector3f	rotate_arround_z(sfVector3f vector, float angle)
{
  vector.x = vector.x * cos(angle) + vector.y * -sin(angle);
  vector.y = vector.x * sin(angle) + vector.y * cos(angle);
  return (vector);
}

sfVector3f	rotate_xyz(sfVector3f to_rotate, sfVector3f angles)
{
  sfVector3f	to_return;

  to_return = rotate_arround_x(to_rotate, angle.x);
  to_return = rotate_arround_y(to_return, angle.y);
  to_return = rotate_arround_z(to_return, angle.z);
  return (to_return);
}

sfVector3f	rotate_zyx(sfVector3f to_rotate, sfVector3f angles)
{
  sfVector3f	to_return;

  to_return = rotate_arround_z(to_rotate, angle.z);
  to_return = rotate_arround_y(to_return, angle.y);
  to_return = rotate_arround_x(to_return, angle.x);
  return (to_return);
}
