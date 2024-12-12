#include "rt.h"

t_vec vec_init(double x, double y, double z)
{
	t_vec ret;

	ret.x = x;
	ret.y = y;
	ret.z = z;
	return (ret);
}

double vec_x(t_vec a)
{
	return (a.x);
}

double vec_y(t_vec a)
{
	return (a.y);
}

double vec_z(t_vec a)
{
	return (a.z);
}

t_vec vec_add(t_vec a, t_vec b)
{
	t_vec ret;

	ret.x = a.x + b.x;
	ret.y = a.y + b.y;
	ret.z = a.z + b.z;
	return (ret);
}

t_vec vec_add_multiple(int count, ...)
{
	t_vec ret = {0, 0, 0};
	va_list args;
	va_start(args, count);

	for (int i = 0; i < count; i++)
	{
		t_vec vec = va_arg(args, t_vec);
		ret.x += vec.x;
		ret.y += vec.y;
		ret.z += vec.z;
	}

	va_end(args);
	return ret;
}

t_vec vec_rev(t_vec a)
{
	t_vec ret;

	ret.x = -a.x;
	ret.y = -a.y;
	ret.z = -a.z;
	return (ret);
}

t_vec vec_sub(t_vec a, t_vec b)
{
	t_vec ret;

	ret.x = a.x - b.x;
	ret.y = a.y - b.y;
	ret.z = a.z - b.z;
	return (ret);
}

t_vec vec_mul(t_vec a, double t)
{
	t_vec ret;

	ret.x = a.x * t;
	ret.y = a.y * t;
	ret.z = a.z * t;
	return (ret);
}

t_vec vec_div(t_vec a, double t)
{
	t_vec ret;

	ret.x = a.x / t;
	ret.y = a.y / t;
	ret.z = a.z / t;
	return (ret);
}

t_vec vec_cross(t_vec a, t_vec b)
{
	t_vec ret;

	ret.x = a.y * b.z - a.z * b.y;
	ret.y = a.z * b.x - a.x * b.z;
	ret.z = a.x * b.y - a.y * b.x;
	return (ret);
}

double vec_dot(t_vec a, t_vec b)
{
	return (a.x * b.x + a.y * b.y + a.z * b.z);
}

double vec_len_sq(t_vec a)
{
	return (vec_dot(a, a));
}

double vec_len(t_vec a)
{
	return (sqrt(vec_len_sq(a)));
}

// t_vec vec_random_range(double min, double max)
// {
// 	t_vec ret;

// 	ret.x = min + (max - min) * drand48();
// 	ret.y = min + (max - min) * drand48();
// 	ret.z = min + (max - min) * drand48();
// 	return (ret);
// }

bool vec_near_zero(t_vec a)
{
	const double s = 1e-8;

	return (fabs(a.x) < s && fabs(a.y) < s && fabs(a.z) < s);
}

t_vec vec_unit(t_vec a)
{
	return (vec_div(a, vec_len(a)));
}