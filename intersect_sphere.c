/*
** intersect_sphere.c for raytracer in /home/antoine.hartwig/Epitech/Infographie/bsraytracer1
** 
** Made by Antoine Hartwig
** Login   <antoine.hartwig@epitech.net>
** 
** Started on  Fri Feb 24 18:41:12 2017 Antoine Hartwig
** Last update Fri Mar  3 16:38:09 2017 HartWoom
*/

#include "include/my.h"

float	case_1(float a, float b, float delta)
{
  float	k1;
  float	k2;

  k1 = (-b + sqrt(delta)) / (2 * a);
  k2 = (-b - sqrt(delta)) / (2 * a);
  if (k1 <= k2)
    return (k1);
  else
    return (k2);
  return (0);
}

float	case_2(float a, float b)
{
  float	k1;

  k1 = -b / (2 * a);
  return (k1);
}

float	intersect_sphere(sfVector3f eye, sfVector3f dir_v, float radius)
{
  float	a;
  float	b;
  float	c;
  float	delta;

  a = powf(dir_v.x, 2) + powf(dir_v.y, 2) + powf(dir_v.z, 2);
  b = 2 * ((eye.x * dir_v.x) + (eye.y * dir_v.y) + (eye.z * dir_v.z));
  c = powf(eye.x, 2) + powf(eye.y, 2) + powf(eye.z, 2) - powf(radius, 2);
  delta = powf(b, 2) - (4 * a * c);
  if (delta > 0)
    return(case_1(a, b, delta));
  else if (delta == 0)
    return (case_2(a, b));
  else if (delta < 0)
    return (-1);
  return (0);
}
