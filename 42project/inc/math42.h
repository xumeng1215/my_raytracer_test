/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   math42.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fiftyblue <fiftyblue@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/12 23:54:58 by mexu              #+#    #+#             */
/*   Updated: 2025/01/03 10:15:03 by fiftyblue        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MATH42_H
# define MATH42_H

# include <stdbool.h>
# include <math.h>
# include <stdarg.h>

typedef struct s_ray	t_ray;

// vector struct
typedef struct s_vector
{
	double	x;
	double	y;
	double	z;
}	t_vec;

// can be used as t_point3 or t_color
typedef t_vec			t_point3;
typedef t_vec			t_color;

// interval struct
typedef struct s_interval
{
	double	min;
	double	max;
}	t_interval;

// mathmatic
typedef struct s_quadratic
{
	t_vec	oc;
	double	a;
	double	b;
	double	c;
	double	discriminant;
}	t_quadratic;

// vector math functions
t_vec		vec_init(double x, double y, double z);
t_vec		vec_add(t_vec a, t_vec b);
// t_vec		vec_add_multiple(int count, ...);
t_vec		vec_rev(t_vec a);
t_vec		vec_sub(t_vec a, t_vec b);
t_vec		vec_mul(t_vec a, double t);
// t_vec		vec_div(t_vec a, double t);
t_vec		vec_cross(t_vec a, t_vec b);
double		vec_dot(t_vec a, t_vec b);
double		vec_len_sq(t_vec a);
double		vec_len(t_vec a);
// t_vec		vec_unit(t_vec a);
bool		if_vec_zero(t_vec vec);
t_vec		normalize(t_vec vec);
t_vec		point_of_intersect(t_ray *ray, double t);

// interval math functions
t_interval	interval_init(double min, double max);
// double		interval_size(t_interval i);
// bool		interval_contains(t_interval i, double t);
bool		interval_surrounds(t_interval i, double t);
double		clamp_with_interval(double t, t_interval i);
// t_interval	empty_interval(void);
// t_interval	infinite_interval(void);

#endif