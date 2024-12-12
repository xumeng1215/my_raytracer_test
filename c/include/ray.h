#ifndef RAY_H
#define RAY_H

# include "vec3.h"

typedef struct s_ray
{
	t_vec orig;
	t_vec dir;
}	t_ray;

t_ray ray_init(t_vec orig, t_vec dir);
t_vec ray_origin(t_ray r);
t_vec ray_direction(t_ray r);

t_vec ray_at(t_ray r, double t);

#endif // RAY_H
