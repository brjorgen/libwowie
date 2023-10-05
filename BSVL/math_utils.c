#include <math.h>

float	min(float a, float b)
{
    if (a > b)
        return b;
    return a;
}

float 	max(float a, float b)
{
    if (a > b)
        return a;
    return b;
}

float	sqr(float i)
{
	return (i * i);
}

float 	clamp(float x, float upper, float lower)
{
	return min(upper, max(x, lower));
}

float	lerp(float a, float b, float f)
{
	return (a + f * (b - a));
}

float	deg_to_rad(double radians)
{
	return (radians * (180.0 / M_PI));
}
