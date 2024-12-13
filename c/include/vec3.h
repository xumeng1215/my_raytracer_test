#ifndef VEC3_H
#define VEC3_H

#include <stdbool.h>

typedef struct s_vector
{
	double x;
	double y;
	double z;
} t_vec;

typedef t_vec t_color;
typedef t_vec t_point3;

t_vec vec_init(double x, double y, double z);
double vec_x(t_vec a);
double vec_y(t_vec a);
double vec_z(t_vec a);

t_vec vec_add(t_vec a, t_vec b);
t_vec vec_add_multiple(int count, ...);
t_vec vec_rev(t_vec a);
t_vec vec_sub(t_vec a, t_vec b);

t_vec vec_mul(t_vec a, double t);
t_vec vec_div(t_vec a, double t);

t_vec vec_cross(t_vec a, t_vec b);
double vec_dot(t_vec a, t_vec b);

double vec_len_sq(t_vec a);
double vec_len(t_vec a);
// t_vec	vec_random_range(double min, double max);

bool vec_near_zero(t_vec a);

t_vec vec_unit(t_vec a);

#endif // VEC3_H