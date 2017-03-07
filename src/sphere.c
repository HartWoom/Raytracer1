/*
** sphere.c for raytracer in /home/hartwoom/Epitech/Infographie/raytracer1/src
** 
** Made by HartWoom
** Login   <antoine.hartwig@epitech.eu>
** 
** Started on  Tue Mar  7 17:02:24 2017 HartWoom
** Last update Tue Mar  7 19:14:47 2017 HartWoom
*/

#include "../include/my.h"

/* float   case_1(float a, float b, float delta) */
/* { */
/*   float k1; */
/*   float k2; */

/*   k1 = (-b + sqrt(delta)) / (2 * a); */
/*   k2 = (-b - sqrt(delta)) / (2 * a); */
/*   if (k1 <= k2) */
/*     return (k1); */
/*   else */
/*     return (k2); */
/*   return (0); */
/* } */

/* float   case_2(float a, float b) */
/* { */
/*   float k1; */

/*   k1 = -b / (2 * a); */
/*   return (k1); */
/* } */

float   intersect_sphere(sfVector3f eye, sfVector3f dir_v, float radius)
{
  float a;
  float b;
  float c;
  float delta;

  a = powf(dir_v.x, 2) + powf(dir_v.y, 2) + powf(dir_v.z, 2);
  b = 2 * ((eye.x * dir_v.x) + (eye.y * dir_v.y) + (eye.z * dir_v.z));
  c = powf(eye.x, 2) + powf(eye.y, 2) + powf(eye.z, 2) - powf(radius, 2);
  delta = powf(b, 2) - (4 * a * c);
  if (delta > 0)
    return (case_1(a, b, delta));
  else if (delta == 0)
    return (case_2(a, b));
  else if (delta < 0)
    return (-1);
  return (0);
}

/* sfVector3f	get_normal_sphere(sfVector3f intersection_point) */
/* { */
/*   sfVector3f	to_return = {0, 0, 0}; */

/*   return (to_return); */
/* } */
