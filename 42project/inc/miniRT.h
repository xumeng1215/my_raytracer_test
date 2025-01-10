/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   miniRT.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mexu <charlie_xumeng@hotmail.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/06 21:07:26 by fiftyblue         #+#    #+#             */
/*   Updated: 2025/01/07 13:14:43 by mexu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINIRT_H
# define MINIRT_H

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <string.h>
# include <sys/errno.h>
# include <sys/time.h>
# include "mlx.h"
# include "../libft/includes/libft.h"
# include "math42.h"

# define WIDTH 800
# define HEIGHT 600
# define FOCAL_DIST 3
# define EPSILON 1e-6
# define BLACK 0x000000

# if defined(__APPLE__)
#  define ESC 53
#  define LEFT 123
#  define RIGHT 124
#  define UP 126
#  define DOWN 125
# elif defined(__linux__)
#  define ESC 65307
#  define LEFT 65361
#  define RIGHT 65363
#  define UP 65362
#  define DOWN 65364
# endif

# ifndef M_PI
#  define M_PI 3.14159265358979323846
# endif

enum	e_obj
{
	SP,
	PL,
	CY,
}	;

typedef struct s_objs
{
	int		type;
	void	*data;
}	t_objs;

typedef struct t_ambient
{
	double	ratio;
	t_vec	rgb;
}	t_amb;

typedef struct s_camera
{
	t_vec	pos;
	t_vec	vector;
	int		fov;
	double	height;
	double	width;
	t_vec	right;
	t_vec	up;
	t_vec	forward;
	t_vec	dir;
}	t_cam;

typedef struct s_light
{
	t_vec	pos;
	double	ratio;
	t_vec	rgb;
}	t_light;

typedef struct s_sphere
{
	t_vec	center;
	double	diameter;
	t_vec	rgb;
	t_vec	oc;
}	t_sp;

typedef struct s_plane
{
	t_vec	pos;
	t_vec	vec;
	t_vec	rgb;
}	t_pl;

enum	e_cy
{
	NONE,
	SIDE,
	BOTTOM,
	TOP,
}	;

typedef struct s_cylinder
{
	t_vec	center;
	t_vec	vec;
	double	diameter;
	double	height;
	t_vec	rgb;
	int		type;
	t_vec	top_c;
	t_vec	btm_c;
}	t_cy;

typedef struct s_ray
{
	t_vec	pos;
	t_vec	vec;
	double	t;
}	t_ray;

typedef struct s_data
{
	void	*mlx;
	void	*win;
	void	*img;
	int		*img_data;
}	t_data;

typedef struct s_hit
{
	double	t;
	t_objs	*objs;
}	t_hit;

typedef struct s_world
{
	t_cam	*cam;
	t_light	*lt;
	t_amb	*amb;
	t_list	*objs;
	t_data	*data;
	t_ray	*ray;
}	t_world;

/* ====================== PARSE ====================== */
int		parser(int ac, char **av, t_world *world);
// void	parse_file(t_world *world, char **av);
// void	parse_line(t_world *world, char *line);

// env
void	parse_ambient(t_world *world, char **strarray);
void	parse_camera(t_world *world, char **strarray);
void	parse_light(t_world *world, char **strarray);

// obj
void	parse_sphere(t_world *world, char **strarray);
void	parse_plane(t_world *world, char **strarray);
void	parse_cylinder(t_world *world, char **strarray);

// element
t_vec	parse_color(t_world *world, char *str);
t_vec	parse_coordinates(t_world *world, char *str);
t_vec	parse_vector(t_world *world, char *str);

// checker
bool	is_float_char(char c);
bool	valid_ratio(char *str);
bool	valid_rgb(int nbr);
bool	valid_vec(t_vec vec);
double	parse_len(t_world *world, char *str, char **strarray);

// utils
// void	only_space(char *line);
// double	smaller_dbl(double a, double b);

// panic
void	panic(char *msg1, char *msg2, char *msg3, t_world *world);
void	cleanup(t_world *world);

/* ====================== CALC ====================== */
// void	init_ray(t_world *world);
void	calc_ray(t_world *world, int x, int y);
void	init_cam(t_cam *cam);
// void	cam_project_ray(t_cam *cam, int x, int y);

// color
// double	calc_color(t_world *world, t_vec rgb, double intensity);
double	compute_color(t_world *world, t_vec p, t_vec n, t_vec rgb);
double	get_sphear_color(t_world *world, t_sp *sphere);
// t_vec	normal_of_sp(t_world *world, t_sp *sphere, t_vec p);
// t_vec	normal_of_pl(t_world *world, t_pl *plane, t_vec p);

// sphere
double	sp_intersect(t_ray *ray, t_sp *sphere);
double	get_positive_root(double a, double b, double discriminant);

// plane
double	pl_intersect(t_ray *ray, t_pl *plane);
double	plane_formula(t_ray *ray, t_vec pos, t_vec pl_normal);
double	get_plane_color(t_world *world, t_pl *plane);

// cylinder
double	cy_intersect(t_ray *ray, t_cy *cy);
double	intersect_cy_side(t_ray *ray, t_cy *cy);
bool	in_height_range(t_ray *ray, t_cy *cy, double t);
double	intersect_cy_cap(t_ray *ray, t_cy *cy);
bool	in_circle_range(t_ray *ray, double t, t_vec center, double radius);

double	get_cylinder_color(t_world *world, t_cy *cylinder);

/* ====================== RENDER ====================== */
// render
void	init_mlxdata(t_world *world);
void	render(t_world *world);

// UI
// int		hook_(int key, void *param);

// free mlx ptrs
// int		close_win(void *param);
void	free_ptrs(t_world *world);

/* ====================== DEBUG ====================== */
// prnt
void	prnt_world(t_world *world);
void	prnt_vec(t_vec vec);
void	prnt_ray(t_ray *ray);
// void	prnt_hit(t_hit *hit);

// prnt objs
void	prnt_objs(t_list *objs);
void	prnt_sp(t_sp *sphere);
void	prnt_pl(t_pl *plane);
void	prnt_cy(t_cy *cylinder);

#endif
