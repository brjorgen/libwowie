 #include "BSVL.h"

/* it is to be noted that dest should be passed by address here. */

void	vec3f_copy(t_vec3f *dest, t_vec3f src)
{
        dest->x = src.x;
        dest->y = src.y;
        dest->z = src.z;
}

void	vec3f_set(t_vec3f *dest, float x, float y, float z)
{
        dest->x = x;
	dest->y = y;
	dest->z = z;
}

t_vec3f vec3f_add_vec(t_vec3f a, t_vec3f b)
{
	t_vec3f new;

	new.x = b.x + a.x;
	new.y = b.y + a.y;
	new.z = b.z + a.z;
	return (new);
}

t_vec3f vec3f_add_k(t_vec3f a, float k)
{
	t_vec3f new;

	new.x = a.x + k;
	new.y = a.y + k;
	new.z = a.z + k;
	return (new);
}
	
t_vec3f vec3f_sub_vec(t_vec3f a, t_vec3f b)
{
	t_vec3f new;

	new.x = a.x - b.x;
	new.y = a.y - b.y;
	new.z = a.z - b.z;
	return (new);
}

t_vec3f vec3f_sub_k(t_vec3f a, float k)
{
	t_vec3f new;

	new.x = a.x - k;
	new.y = a.y - k;
	new.z = a.z - k;
	return (new);
}

t_vec3f vec3f_div_k(t_vec3f a, float k)
{
	t_vec3f new;
	new.x = a.x / k;
	new.y = a.y / k;
	new.z = a.z / k;
	return (new);
}

t_vec3f vec3f_div_vec(t_vec3f a, t_vec3f b)
{
	t_vec3f new;

	new.x = a.x / b.x;
	new.y = a.y / b.y;
	new.z = a.z / b.z;
	return (new);
}

t_vec3f vec3f_mod_vec(t_vec3f a, t_vec3f b)
{
	t_vec3f new;

	new.x = fmod(a.x , b.x);
	new.y = fmod(a.y , b.y);
	new.z = fmod(a.z , b.z);
	return (new);
}

t_vec3f vec3f_mod_k(t_vec3f a, float k)
{
	t_vec3f new;

	new.x = fmod(a.x , k);
	new.y = fmod(a.y , k);
	new.z = fmod(a.z , k);
	return (new);
}

t_vec3f vec3f_mul_vec(t_vec3f a, t_vec3f b)
{
	t_vec3f new;

	new.x = a.x * b.x;
	new.y = a.y * b.y;
	new.z = a.z * b.z;
	return (new);
}

t_vec3f vec3f_mul_k(t_vec3f a, float k)
{
	t_vec3f new;

	new.x = a.x * k;
	new.y = a.y * k;
	new.z = a.z * k;
	return (new);
}

float	vec3f_dotprod(t_vec3f a, t_vec3f b) // how similar are the two vecs?
{
	t_vec3f dest;
	float	res;

	dest.x = a.x * b.x;
	dest.y = a.y * b.y;
	dest.z = a.z * b.z;
	res = dest.x + dest.y + dest.z;
	return (res);
}

t_vec3f	vec3f_crossprod(t_vec3f a, t_vec3f b) // get normal
{
	t_vec3f dest;

	dest.x = a.y * b.z - b.y * a.z;
	dest.y = a.z * b.x - b.z * a.x;
	dest.z = a.x * b.y - b.x * a.y;
	return (dest);
}

t_vec3f vec3f_normalize(t_vec3f a)
{
	float vec_len;
	t_vec3f vec;

	vec_len = vec3f_dist_origin(a);
	vec.x = a.x / vec_len;
	vec.y = a.y / vec_len;
	vec.z = a.z / vec_len;
	return (vec);
}

float	vec3f_dist_origin(t_vec3f a)
{
        float x;
	float y;
	float z;

	x = a.x * a.x; // x^2
	y = a.y * a.y; // y^2
	z = a.z * a.z; // z^2
	return (sqrt(x + y + z));
}

float	vec3f_dist_ab(t_vec3f a, t_vec3f b)
{
	float x ;
	float y ;
	float z ;

	x = (b.x - a.x) * (b.x - a.x); // (x2 - x1)^2
	y = (b.y - a.y) * (b.y - a.y); // (y2 - y1)^2
	z = (b.z - a.z) * (b.z - a.z); // (z2 - z1)^2
	return (sqrt(x + y + z));
}

t_vec3f vec3f_apply_fn_int(t_vec3f a, int(*fn)(int k))
{
	t_vec3f new;

	new.x = fn(a.x);
	new.y = fn(a.y);
	new.z = fn(a.z);
	return (new);
}

t_vec3f vec3f_apply_fn_float(t_vec3f a, float(*fn)(float k))
{
	t_vec3f new;

	new.x = fn(a.x);
	new.y = fn(a.y);
	new.z = fn(a.z);
	return (new);
}

t_vec3f vec3f_max(t_vec3f a, t_vec3f b)
{
	t_vec3f vector;

	vector.x = max(a.x , b.x);
	vector.y = max(a.y , b.y);
	vector.z = max(a.z , b.z);
	return vector;
}

t_vec3f vec3f_min(t_vec3f a, t_vec3f b)
{
	t_vec3f vector;

	vector.x = min(a.x , b.x);
	vector.y = min(a.y , b.y);
	vector.z = min(a.z , b.z);
	return vector;
}

t_vec3f vec3f_mul_mat3(t_vec3f a, t_vec3f mat[3])
{
	t_vec3f	tmp;
	t_vec3f	res;

	tmp = vec3f_mul_vec(a, (t_vec3f){mat[0].x, mat[1].x, mat[2].x});
	res.x = tmp.x + tmp.y + tmp.z;
	tmp = vec3f_mul_vec(a, (t_vec3f){mat[0].y, mat[1].y, mat[2].y});
	res.y = tmp.x + tmp.y + tmp.z;
	tmp = vec3f_mul_vec(a, (t_vec3f){mat[0].z, mat[1].z, mat[2].z});
	res.z = tmp.x + tmp.y + tmp.z;
	return (res);
}

t_vec3f	vec3f_mul_mat4f(t_vec3f a, t_vec4f mat[static 4]){
	t_vec4f tmp;

	tmp = (t_vec4f){a.x, a.y, a.z, 1};
	tmp = vec4f_mul_mat4f(tmp, mat);
	return ((t_vec3f){tmp.x, tmp.y, tmp.z});
}

void	get_vec3_identity_matrix(t_mat3 mat)
{
	mat[0] = (t_vec3f){1,	 0,	0};
	mat[1] = (t_vec3f){0,	 1,	0};
	mat[2] = (t_vec3f){0,	 0,	1};
}

void	get_roll_matrix(float theta, t_mat3 mat)  // x
{
	mat[0] = (t_vec3f){1,		0,		0};
	mat[1] = (t_vec3f){0,		cos(theta),	-sin(theta)};
	mat[2] = (t_vec3f){0,		sin(theta),	cos(theta)};
}

void	get_pitch_matrix(float theta, t_mat3 mat) // y
{
	mat[0] = (t_vec3f){cos(theta),	 0,		sin(theta)};
	mat[1] = (t_vec3f){0,		 1,		0};
	mat[2] = (t_vec3f){-sin(theta),  0,		cos(theta)};
}

void	get_yaw_matrix(float theta, t_mat3 mat)   // z
{
	mat[0] = (t_vec3f){cos(theta),	 -sin(theta),	0};
	mat[1] = (t_vec3f){sin(theta),	 cos(theta),	0};
	mat[2] = (t_vec3f){0,		 0,		1};
}

void	get_rotation_matrix(float theta, enum axis axis, t_mat3 mat){
	static void (*const rot_fptr[__AXIS_TOTAL])(float, t_vec3f *) = {
		&get_roll_matrix,
		&get_pitch_matrix,
		&get_yaw_matrix
	};

	rot_fptr[axis](theta, &mat[0]);
}

void	apply_rotation_matrix(t_vec3f *vec_addr, t_mat3 mat){
	*vec_addr = vec3f_mul_mat3(*vec_addr, mat);
}

void	get_and_apply_rotation_matrix(float theta, enum axis axis, t_vec3f *vec_addr)
{
	t_vec3f	mat[3] = (t_vec3f [3]){[0 ... 2] = {.x = 0, .y = 0, .z = 0}};
	get_rotation_matrix(theta, axis, &mat[0]);
	apply_rotation_matrix(vec_addr, &mat[0]);
}

bool	vec3f_cmp(t_vec3f a, t_vec3f b)
{
	bool cmp[__AXIS_TOTAL] = (bool []){
		[X] = a.x == b.x ? true : false,
		[Y] = a.y == b.y ? true : false,
		[Z] = a.z == b.z ? true : false,
	};

	return (cmp[X] && cmp[Y] && cmp[Z]);
}

t_vec3f vec3_lerp(t_vec3f a, t_vec3f b, float t)
{
	return ((t_vec3f) {
			.x = a.x + (b.x - a.x) * t,
			.y = a.y + (b.y - a.y) * t,
			.z = a.z + (b.z - a.z) * t
		});
}

t_vec3f		refract(t_vec3f i, t_vec3f n, float n1, float n2, float radical)
{
	return (vec3f_sub_vec(
		vec3f_mul_k(vec3f_sub_vec(i, vec3f_mul_k(n, vec3f_dotprod(i, n))), n1 / n2),
		vec3f_mul_k(n, sqrt(radical))));
}

t_vec3f		reflect(t_vec3f i, t_vec3f n)
{
	return (vec3f_sub_vec(i, vec3f_mul_k(n, vec3f_dotprod(i, n) * 2)));
}
