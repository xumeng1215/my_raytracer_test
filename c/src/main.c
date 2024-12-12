#include "rt.h"

double hit_sphere(const t_point3 *center, double radius, const t_ray *r)
{
	t_vec oc = vec_sub(*center, r->orig);
	double a = vec_len_sq(r->dir);
	double h = vec_dot(r->dir, oc);
	double c = vec_len_sq(oc) - radius * radius;
	double discriminant = h * h - a * c;

	if (discriminant < 0)
		return -1.0;
	else
		return (h - sqrt(discriminant)) / a;
}

t_color ray_color(const t_ray *r)
{
	t_point3 sphere_center = vec_init(0, 0, -1);
	double t = hit_sphere(&sphere_center, 0.5, r);
	if (t > 0.0)
	{
		t_vec N = vec_unit(vec_sub(ray_at(*r, t), sphere_center));
		return vec_mul(vec_add(N, vec_init(1, 1, 1)), 0.5);
	}
	// if (hit_sphere(&sphere_center, 0.5, r))
	// 	return vec_init(1, 0, 0);
	t_vec unit_direction = vec_unit(r->dir);
	double a = 0.5 * (unit_direction.y + 1.0);
	return vec_add(vec_mul(vec_init(0.5, 0.7, 1.0), a), vec_mul(vec_init(1, 1, 1), 1.0 - a));
}

int main()
{
	// image
	double aspect_ratio = 16.0 / 9.0;
	int image_width = 1080;

	// calculate image height
	int image_height = (int)(image_width / aspect_ratio);
	image_height = (image_height < 1) ? 1 : image_height;

	// camera
	double focal_length = 1.0;
	double viewport_height = 2.0;
	double viewport_width = viewport_height * (((double)(image_width)) / image_height);
	t_point3 camera_center = vec_init(0, 0, 0);

	t_vec viewport_u = vec_init(viewport_width, 0, 0);
	t_vec viewport_v = vec_rev(vec_init(0, viewport_height, 0));

	t_vec pixel_delta_u = vec_div(viewport_u, image_width);
	t_vec pixel_delta_v = vec_div(viewport_v, image_height);

	t_vec viewport_upper_left = vec_add_multiple(4, camera_center, vec_rev(vec_init(0, 0, focal_length)),
												 vec_div(viewport_u, -2), vec_div(viewport_v, -2));
	t_point3 pixel00_loc = vec_add(viewport_upper_left, vec_mul(vec_add(pixel_delta_u, pixel_delta_v), 0.5));

	printf("P3\n%d %d\n255\n", image_width, image_height);

	for (int j = image_height - 1; j >= 0; j--)
	{
		fprintf(stderr, "\rScanlines remaining: %d ", image_height - j);
		fflush(stderr);
		for (int i = 0; i < image_width; i++)
		{
			t_point3 pixel_center = vec_add_multiple(3, pixel00_loc, vec_mul(pixel_delta_u, i), vec_mul(pixel_delta_v, j));
			t_vec ray_direction = vec_sub(pixel_center, camera_center);
			t_ray r = ray_init(camera_center, ray_direction);

			t_color pixel_color = ray_color(&r);
			write_color(&pixel_color);
		}
	}
	fprintf(stderr, "\rDone.                 \n");
	fflush(stderr);
}