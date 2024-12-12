#ifndef SHAPE_H
#define SHAPE_H

#include "hit.h"

typedef struct s_sphere
{
	t_point3 center;
	double radius;
} t_sphere;

bool hit_sphere(const t_sphere *sphere, const t_ray *r, double t_min, double t_max, t_hit_record *rec);

#endif // SHAPE_H