#ifndef RT_H
#define RT_H

# include <stdio.h>
# include <stdbool.h>
# include <stdlib.h>
# include <math.h>
# include <stdarg.h>

# include "vec3.h"
# include "ray.h"

void write_color(t_vec *pixel_color);
t_color ray_color(const t_ray *r);


#endif // RT_H