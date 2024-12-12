#include "rt.h"

t_ray ray_init(t_vec orig, t_vec dir)
{
	t_ray ret;

	ret.orig = orig;
	ret.dir = dir;
	return (ret);
}

t_vec ray_origin(t_ray r)
{
	return (r.orig);
}

t_vec ray_direction(t_ray r)
{
	return (r.dir);
}

t_vec ray_at(t_ray r, double t)
{
	t_vec ret;

	ret = vec_add(r.orig, vec_mul(r.dir, t));
	return (ret);
}
