#ifndef HIT_H
#define HIT_H

#include "ray.h"
#include "vec3.h"

typedef struct  s_hit_record
{
	t_point3 p;
	t_vec normal;
	double t;
	bool front_face;
}				t_hit_record;

void hit_record_set_face_normal(t_hit_record *rec, const t_ray *r, const t_vec *outward_normal);

#endif // HIT_H