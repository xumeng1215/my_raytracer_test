#ifndef HIT_H
#define HIT_H

#include "ray.h"
#include "vec3.h"

typedef struct  s_hit_record
{
	t_point3 p;
	t_vec normal;
	double t;
	// bool front_face;
}				t_hit_record;



#endif // HIT_H