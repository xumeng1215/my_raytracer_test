#include "rtweekend.h"
#include "hittable.h"
#include "hittable_list.h"
#include "sphere.h"
#include "camera.h"
#include "material.h"

// double hit_sphere(const point3 &center, double radius, const ray &r)
// {
// 	vec3 oc = center - r.origin();
// 	// auto a = dot(r.direction(), r.direction());
// 	auto a = r.direction().length_squared();

// 	// b = -2h
// 	auto h = dot(r.direction(), oc);
// 	// auto b = -2.0 * dot(r.direction(), oc);
// 	auto c = oc.length_squared() - radius * radius;
// 	auto discriminant = h * h - a * c;

// 	if (discriminant < 0)
// 		return -1.0;
// 	else
// 		return (h - std::sqrt(discriminant)) / a;

// 	// return (discriminant>=0);
// }

// color ray_color(const ray &r, const hittable& world)
// {
// 	hit_record rec;
// 	if(world.hit(r, interval(0, infinity), rec))
// 	{
// 		return 0.5 * (rec.normal + color(1, 1, 1));
// 	}

// 	vec3 unit_direction = unit_vector(r.direction());
// 	auto a = 0.5 * (unit_direction.y() + 1.0);
// 	return (1.0 - a) * color(1, 1, 1) + a * color(0.5, 0.7, 1.0);
// }
int main()
{
	hittable_list world;

	auto material_ground = make_shared<lambertian>(color(0.8, 0.8, 0.0));
	auto material_center = make_shared<lambertian>(color(0.1, 0.2, 0.5));
	auto material_left = make_shared<metal>(color(0.8, 0.8, 0.8));
	auto material_right = make_shared<metal>(color(0.8, 0.6, 0.2));

	// world.add(make_shared<sphere>(point3(0, -100.5, -1), 100));
	// world.add(make_shared<sphere>(point3(0, 0, -1), 0.5));

	world.add(make_shared<sphere>(point3(0, -100.5, -1), 100, material_ground));
	world.add(make_shared<sphere>(point3(0, 0, -1.2), 0.5, material_center));
	world.add(make_shared<sphere>(point3(-1, 0, -1), 0.5, material_left));
	world.add(make_shared<sphere>(point3(1, 0, -1), 0.5, material_right));

	camera cam;

	cam.aspect_ratio = 16.0 / 9.0;
	cam.image_width = 400;
	cam.samples_per_pixel = 100;
	cam.max_depth = 50;

	cam.render(world);
}
