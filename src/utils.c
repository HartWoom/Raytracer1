/*
** utils.c for raytracer in /home/hartwoom/Epitech/Infographie/raytracer1
** 
** Made by HartWoom
** Login   <antoine.hartwig@epitech.eu>
** 
** Started on  Tue Mar  7 19:06:47 2017 HartWoom
** Last update Tue Mar  7 19:13:58 2017 HartWoom
*/

#include "../include/my.h"

float   case_1(float a, float b, float delta)
{
  float k1;
  float k2;

  k1 = (-b + sqrt(delta)) / (2 * a);
  k2 = (-b - sqrt(delta)) / (2 * a);
  if (k1 <= k2)
    return (k1);
  else
    return (k2);
  return (0);
}

float   case_2(float a, float b)
{
  float k1;

  k1 = -b / (2 * a);
  return (k1);
}
