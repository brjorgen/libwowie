#include "BSVL.h"

void	vec2f_copy(t_vec2f *dest, t_vec2f src)
{
        dest->x = src.x;
        dest->y = src.y;
}

void	vec2f_set(t_vec2f *dest, float x, float y)
{
        dest->x = x;
	dest->y = y;
}

t_vec2f vec2f_add(t_vec2f a, t_vec2f b)
{
	t_vec2f new;

	new.x = b.x + a.x;
	new.y = b.y + a.y;
	return (new);
}
	
t_vec2f vec2f_sub(t_vec2f a, t_vec2f b)
{
	t_vec2f new;

	new.x = a.x - b.x;
	new.y = a.y - b.y;
	return (new);
}

t_vec2f vec2f_div_k(t_vec2f a, float k)
{
	t_vec2f new;

	new.x = a.x / k;
	new.y = a.y / k;
	return (new);
}

t_vec2f vec2f_div_vec(t_vec2f a, t_vec2f b)
{
	t_vec2f new;

	new.x = a.x / b.x;
	new.y = a.y / b.y;
	return (new);
}

t_vec2f vec2f_mul_vec(t_vec2f a, t_vec2f b)
{
	t_vec2f new;

	new.x = a.x * b.x;
	new.y = a.y * b.y;
	return (new);
}

t_vec2f	vec2f_mul_mat2f(t_vec2f a, t_vec2f mat[2]) {
	t_vec2f res;
	t_vec2f l1;
	t_vec2f l2;

	l1 = vec2f_mul_vec(a, (t_vec2f){mat[0].x, mat[1].x});
	l2 = vec2f_mul_vec(a, (t_vec2f){mat[0].y, mat[1].y});
	res = (t_vec2f){
		.x = l1.x + l1.y,
		.y = l2.x + l2.y,
	};
	return (res);
}

t_vec2f vec2f_mul_k(t_vec2f a, float k)
{
	t_vec2f new;

	new.x = a.x * k;
	new.y = a.y * k;
	return (new);
}

float	vec2f_dotprod(t_vec2f a, t_vec2f b) // how similar are the two vecs?
{
	t_vec2f dest;
	float	res;

	dest.x = a.x * b.x;
	dest.y = a.y * b.y;
	res = dest.x + dest.y;
	return (res);
}

float	vec2f_dist_origin(t_vec2f a){
        float x;
	float y;

	x = a.x * a.x; // x^2
	y = a.y * a.y; // y^2
	return (sqrt(x + y));
}

t_vec2f vec2f_normalize(t_vec2f a){
	float vec_len;
	t_vec2f vec;

	vec_len = vec2f_dist_origin(a);
	vec = vec2f_div_k(a, vec_len);
	return (vec);
}

float	vec2f_dist_ab(t_vec2f a, t_vec2f b){
	float x ;
	float y ;

	x = (b.x - a.x) * (b.x - a.x); // (x2 - x1)^2
	y = (b.y - a.y) * (b.y - a.y); // (y2 - y1)^2
	return (sqrt(x + y));
}

t_vec2f vec2f_apply_fn_float(t_vec2f a, float(*fn)(float k)){
	t_vec2f new;

	new.x = fn(a.x);
	new.y = fn(a.y);
	return (new);
}

t_vec2f vec2f_apply_fn_int(t_vec2f a, int(*fn)(float k)){
	t_vec2f new;

	new.x = fn(a.x);
	new.y = fn(a.y);
	return (new);
}

