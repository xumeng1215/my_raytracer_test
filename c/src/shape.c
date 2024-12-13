#include "shape.h"

t_sphere *new_sphere(t_point3 center, double radius)
{
	t_sphere *sphere = malloc(sizeof(t_sphere));
	if (!sphere)
		return (NULL);
	sphere->center = center;
	sphere->radius = radius;
	return (sphere);
}

bool hit_sphere(const t_sphere *sphere, const t_ray *r, double t_min, double t_max, t_hit_record *rec)
{
	t_vec oc = vec_sub(sphere->center, r->orig);
	double a = vec_len_sq(r->dir);
	double h = vec_dot(r->dir, oc);
	double c = vec_len_sq(oc) - sphere->radius * sphere->radius;
	double discriminant = h * h - a * c;
	if(discriminant < 0)
		return (false);
	double sqrtd = sqrt(discriminant);

	double root = (h-sqrtd) / a;
	if(t_min >= root || root >= t_max)
	{
		root = (h+sqrtd) / a;
		if(t_min >= root || root >= t_max)
			return (false);
	}
	rec->t = root;
	rec->p = ray_at(*r, rec->t);
	t_vec outward_normal = vec_div(vec_sub(rec->p, sphere->center), sphere->radius);
	hit_record_set_face_normal(rec, r, &outward_normal);
	return (true);
}