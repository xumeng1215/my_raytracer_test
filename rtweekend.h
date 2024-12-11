#ifndef RTWEEKEND_H
#define RTWEEKEND_H	

#include <cmath>
#include <limits>
#include <memory>
#include <iostream>

using std::shared_ptr;
using std::make_shared;

const double infinity = std::numeric_limits<double>::infinity();

const double pi = 3.1415926535897932385;

inline double degrees_to_radians(double degrees)
{
	return degrees * pi / 180.0;
}

#include "color.h"
#include "vec3.h"
#include "ray.h"
#include "interval.h"

#endif // RTWEEKEND_H