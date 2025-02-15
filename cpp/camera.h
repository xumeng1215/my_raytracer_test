#ifndef CAMERA_H
#define CAMERA_H

#include "hittable.h"
#include "material.h"
class camera
{
public:
	double aspect_ratio = 1.0;	// Ratio of image width over height
	int image_width = 100;		// Rendered image width in pixel count
	int samples_per_pixel = 10; // Count of random samples for each pixel
	int max_depth = 10;			// Maximum recursion depth

	double vfov = 90;				   // Vertical field-of-view in degrees
	point3 lookfrom = point3(0, 0, 0); // camera is looking from this point
	point3 lookat = point3(0, 0, -1);  // camera is looking at this point
	vec3 vup = vec3(0, 1, 0);		   // camera relative up vector

	double defoucs_angle = 0;
	double focus_dist = 10;

	void render(const hittable &world)
	{
		initialize();

		std::cout << "P3\n"
				  << image_width << ' ' << image_height << "\n255\n";

		for (int j = 0; j < image_height; j++)
		{
			std::clog << "\rScanlines remaining: " << (image_height - j) << ' ' << std::flush;
			for (int i = 0; i < image_width; i++)
			{
				// auto pixel_center = pixel00_loc + (i * pixel_delta_u) + (j * pixel_delta_v);
				// auto ray_direction = pixel_center - center;
				// ray r(center, ray_direction);

				// color pixel_color = ray_color(r, world);
				// write_color(std::cout, pixel_color);

				color pixel_color(0, 0, 0);
				for (int sample = 0; sample < samples_per_pixel; sample++)
				{
					ray r = get_ray(i, j);
					pixel_color += ray_color(r, max_depth, world);
				}
				write_color(std::cout, pixel_samples_scale * pixel_color);
			}
		}

		std::clog << "\rDone.                 \n";
	}

private:
	int image_height;			// Rendered image height
	point3 center;				// Camera center
	point3 pixel00_loc;			// Location of pixel 0, 0
	vec3 pixel_delta_u;			// Offset to pixel to the right
	vec3 pixel_delta_v;			// Offset to pixel below
	double pixel_samples_scale; // Color scale factor for a sum of pixel samples
	vec3 u, v, w;
	vec3 defocus_disk_u;
	vec3 defocus_disk_v;

	void initialize()
	{
		image_height = int(image_width / aspect_ratio);
		image_height = (image_height < 1) ? 1 : image_height;
		pixel_samples_scale = 1.0 / samples_per_pixel;

		center = lookfrom;

		// Determine viewport dimensions.
		// auto focal_length = (lookfrom - lookat).length();
		auto theta = degrees_to_radians(vfov);
		auto h = std::tan(theta / 2);
		auto viewport_height = 2 * h * focus_dist;
		auto viewport_width = viewport_height * (double(image_width) / image_height);

		// Calculate the camera basis vectors u, v, and w.
		// this defines the camera coordinate system.
		w = unit_vector(lookfrom - lookat);
		u = unit_vector(cross(vup, w));
		v = cross(w, u);

		// Calculate the vectors across the horizontal and down the vertical viewport edges.
		// auto viewport_u = vec3(viewport_width, 0, 0);
		// auto viewport_v = vec3(0, -viewport_height, 0);
		vec3 viewport_u = viewport_width * u;
		vec3 viewport_v = viewport_height * -v;

		// Calculate the horizontal and vertical delta vectors from pixel to pixel.
		pixel_delta_u = viewport_u / image_width;
		pixel_delta_v = viewport_v / image_height;

		// Calculate the location of the upper left pixel.
		auto viewport_upper_left =
			center - (focus_dist * w) - viewport_u / 2 - viewport_v / 2;
		pixel00_loc = viewport_upper_left + 0.5 * (pixel_delta_u + pixel_delta_v);

		auto defocus_radius = focus_dist * std::tan(degrees_to_radians(defoucs_angle / 2));
		defocus_disk_u = u * defocus_radius;
		defocus_disk_v = v * defocus_radius;
	}

	vec3 sample_square() const
	{
		return vec3(random_double() - 0.5, random_double() - 0.5, 0);
	}

	point3 defocus_disk_sample() const
	{
		auto p = random_in_unit_disk();
		return center + (p[0] * defocus_disk_u) + (p[1] * defocus_disk_v);
	}

	ray get_ray(int i, int j) const
	{
		auto offset = sample_square();
		auto pixel_sample = pixel00_loc + ((i + offset.x()) * pixel_delta_u) + ((j + offset.y()) * pixel_delta_v);

		auto ray_origin = (defoucs_angle <= 0) ? center : defocus_disk_sample();
		auto ray_direction = pixel_sample - ray_origin;
		auto ray_time = random_double();
		return ray(ray_origin, ray_direction, ray_time);
	}

	color ray_color(const ray &r, int depth, const hittable &world) const
	{

		if (depth <= 0)
			return color(0, 0, 0);

		hit_record rec;

		if (world.hit(r, interval(0.001, infinity), rec))
		{
			ray scattered;
			color attenuation;

			if (rec.mat->scatter(r, rec, attenuation, scattered))
				return attenuation * ray_color(scattered, depth - 1, world);
			return color(0, 0, 0);

			// vec3 direction = random_on_hemisphere(rec.normal);
			// vec3 direction = rec.normal + random_unit_vector();
			// // return 0.5 * (rec.normal + color(1, 1, 1));
			// return 0.5 * ray_color(ray(rec.p, direction), depth - 1, world);
		}

		vec3 unit_direction = unit_vector(r.direction());
		auto a = 0.5 * (unit_direction.y() + 1.0);
		return (1.0 - a) * color(1.0, 1.0, 1.0) + a * color(0.5, 0.7, 1.0);
	}
};

#endif // CAMERA_H