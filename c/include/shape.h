#ifndef SHAPE_H
#define SHAPE_H
#include <stdlib.h>
#include "hit.h"

typedef struct s_object
{
	void *shape;
	bool (*hit)(const void *shape, const t_ray *r, double t_min, double t_max, t_hit_record *rec);
} t_object;

typedef struct s_sphere
{
	t_point3 center;
	double radius;
} t_sphere;
t_sphere *new_sphere(t_point3 center, double radius);
bool hit_sphere(const t_sphere *sphere, const t_ray *r, double t_min, double t_max, t_hit_record *rec);

#endif // SHAPE_H