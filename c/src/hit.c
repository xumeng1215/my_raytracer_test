#include "hit.h"

void hit_record_set_face_normal(t_hit_record *rec, const t_ray *r, const t_vec *outward_normal)
{
	rec->front_face = vec_dot(r->dir, *outward_normal) < 0;
	rec->normal = rec->front_face ? *outward_normal : vec_rev(*outward_normal);
}