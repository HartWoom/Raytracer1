/*
** rotate.c for raytracer in /home/hartwoom/Epitech/Infographie/raytracer1/src
** 
** Made by HartWoom
** Login   <antoine.hartwig@epitech.eu>
** 
** Started on  Tue Mar  7 16:59:50 2017 HartWoom
** Last update Thu Mar 16 14:33:11 2017 HartWoom
*/

#include "my.h"

sfVector3f	rotate_arround_x(sfVector3f vector, float angle)
{
  sfVector3f	to_return;

  to_return = vector;
  to_return.y = vector.y * (M_PI * cosf(angle) / 180)
    + vector.z * (M_PI * -sin(angle) / 180);
  to_return.z = vector.y * (M_PI * sinf(angle) / 180)
    + vector.z * (M_PI * cos(angle) / 180);
  return (to_return);
}

sfVector3f	rotate_arround_y(sfVector3f vector, float angle)
{
  sfVector3f	to_return;

  to_return = vector;
  to_return.x = vector.x * (M_PI * cos(angle) / 180)
    + vector.z * (M_PI * sin(angle) / 180);
  to_return.z = vector.x * (M_PI * -sin(angle) / 180)
    + vector.z * (M_PI * cos(angle) / 180);
  return (to_return);
}

sfVector3f	rotate_arround_z(sfVector3f vector, float angle)
{
  sfVector3f	to_return;

  to_return = vector;
  to_return.x = vector.x * (M_PI * cos(angle) / 180)
    + vector.y * (M_PI * -sin(angle) / 180);
  to_return.y = vector.x * (M_PI * sin(angle) / 180)
    + vector.y * (M_PI * cos(angle) / 180);
  return (to_return);
}

sfVector3f	rotate_xyz(sfVector3f to_rotate, sfVector3f angles)
{
  
  to_rotate = rotate_arround_x(to_rotate, angles.x);
  to_rotate = rotate_arround_y(to_rotate, angles.y);
  to_rotate = rotate_arround_z(to_rotate, angles.z);
  return (to_rotate);
}

sfVector3f	rotate_zyx(sfVector3f to_rotate, sfVector3f angles)
{
  to_rotate = rotate_arround_z(to_rotate, angles.z);
  to_rotate = rotate_arround_y(to_rotate, angles.y);
  to_rotate = rotate_arround_x(to_rotate, angles.x);
  return (to_rotate);
}
