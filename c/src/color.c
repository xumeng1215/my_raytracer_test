#include "rt.h"

void write_color(t_vec *pixel_color)
{
	int ir = (int)(255.999 * pixel_color->x);
	int ig = (int)(255.999 * pixel_color->y);
	int ib = (int)(255.999 * pixel_color->z);

	printf("%d %d %d\n", ir, ig, ib);
}




