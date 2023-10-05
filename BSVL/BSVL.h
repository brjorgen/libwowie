#ifndef BSVL_H
# define BSVL_H
# include <stdint.h>
# include <math.h>
# include <stdlib.h>
# include <stdbool.h>

typedef struct		s_vec2f
{
	float		x;
	float		y;
}			t_vec2f;

typedef struct		s_vec3f
{
	float		x;
	float		y;
	float		z;
}			t_vec3f;

typedef struct		s_vec4f
{
	float		x;
	float		y;
	float		z;
	float		w;
}			t_vec4f;

typedef t_vec3f		t_mat3[3];
typedef t_vec4f		t_mat4[4];

typedef struct		s_tri
{
	t_vec3f		a;
	t_vec3f		b;
	t_vec3f		c;
}			t_tri;

typedef struct		s_ray
{
	t_vec3f		origin;
	t_vec3f		direction;
}			t_ray;

typedef struct		s_cam
{
	t_ray		posdata;
	float		fov;
	t_vec3f		focus;
}			t_cam;

enum			axis
{
	X,
	Y,
	Z,
	__AXIS_TOTAL
};

/*
** ----- Matrix operations
*/

/*
** -------- vec2
*/

t_vec2f		vec2f_mul_mat2f(t_vec2f a, t_vec2f mat[static 2]);

/*
** -------- vec3
*/

t_vec3f		vec3f_mul_mat3(t_vec3f a, t_vec3f mat[static 3]);

void		get_roll_matrix(float theta, t_vec3f mat[static 3]);
void		get_pitch_matrix(float theta, t_vec3f mat[static 3]);
void		get_yaw_matrix(float theta, t_vec3f mat[static 3]);

void		get_rotation_matrix(float theta, enum axis axis, t_vec3f mat[static 3]);
void		apply_rotation_matrix(t_vec3f *vec_addr, t_vec3f mat[static 3]);
void		get_and_apply_rotation_matrix(float theta, enum axis axis, t_vec3f *vec_addr); // interface to roll pitch and yaw

t_vec3f		vec3f_mul_mat4f(t_vec3f a, t_vec4f mat[static 4]);

void		get_vec3_identity_matrix(t_vec3f mat[static 3]);

/*
** -------- vec4
*/

t_vec4f		vec4f_mul_mat4f(t_vec4f a, t_vec4f mat[static 4]);
void		get_arbitrary_rot_mat(t_vec3f axis, float angle, t_vec4f mat[static 4]);
void		get_view_matrix(t_vec3f eye, t_vec3f center, t_vec3f up, t_vec4f mat[static 4]);
void		get_translation_matrix(t_vec3f translation_vector, t_vec4f mat[static 4]);
void		get_and_apply_translation_matrix(t_vec3f *target_addr, t_vec3f translation_vector);
void		get_vec4_identity_matrix(t_vec4f mat[static 4]);

/*
** ----- Vector operations
*/

/*
** ------- initialization functions (IMPURE FUNCTIONS)
** copy -> copies the content of src into dest
** set  -> sets the xyz values of dest to the xyz values passed as arg 
*/

void		vec3f_copy(t_vec3f *dest, t_vec3f src);
void		vec3f_set(t_vec3f *dest, float x, float y, float z);

/*
** ------- operations returnning vectors (PURE FUNCTIONS)
** add  -> returns the vector resulting from the addition of the a and b vectors
** sub  -> returns the vector resulting from the substraction of the a and b vectors
** div_vec  -> returns the vector resulting from the division of vectors a and b
** div_k  -> returns the vector resulting from the division of vector a and scalar value k
** mul_vec -> returns the vector resulting from the multiplication of vectors a and b
** mul_k->  returns the vector resulting from the multiplication of vector a and scalar  b
** scale-> returns the vector resulting from the multiplication of vector a and scalar value k
** crossprod -> returns the vector resulting from cross product of the a and b vectors
** dotprod -> returns the vector resulting from dot product of the a and b vectors
** get_unitvec -> returns normalized a vector
*/

/*
** -------- vec4
*/

t_vec4f		vec4f_mul_vec(t_vec4f a, t_vec4f b);


/*
** -------- vec3
*/

t_vec3f 	vec3f_add_vec(t_vec3f a, t_vec3f b);
t_vec3f 	vec3f_add_k(t_vec3f a, float k);
t_vec3f 	vec3f_sub_vec(t_vec3f a, t_vec3f b);
t_vec3f 	vec3f_sub_k(t_vec3f a, float k);
t_vec3f 	vec3f_div_vec(t_vec3f a, t_vec3f b);
t_vec3f 	vec3f_div_k(t_vec3f a, float k);
t_vec3f 	vec3f_mul_vec(t_vec3f a, t_vec3f b);
t_vec3f 	vec3f_mul_k(t_vec3f a, float k);
t_vec3f		vec3f_crossprod(t_vec3f a, t_vec3f b);
t_vec3f 	vec3f_normalize(t_vec3f a);
t_vec3f 	vec3f_apply_fn_int(t_vec3f a, int(*fn)(int k));
t_vec3f 	vec3f_apply_fn_float(t_vec3f a, float(*fn)(float k));
t_vec3f 	vec3f_max(t_vec3f a, t_vec3f b);
t_vec3f 	vec3f_min(t_vec3f a, t_vec3f b);
t_vec3f 	vec3f_mod_vec(t_vec3f a, t_vec3f b);
t_vec3f 	vec3f_mod_k(t_vec3f a, float k);

bool		vec3f_cmp(t_vec3f a, t_vec3f b);
t_vec3f		vec3_lerp(t_vec3f a, t_vec3f b, float t);
t_vec3f		refract(t_vec3f i, t_vec3f n, float n1, float n2, float radical);
t_vec3f		reflect(t_vec3f i, t_vec3f n);

/*
** -------- vec2
*/

t_vec2f 	vec2f_add(t_vec2f a, t_vec2f b);
t_vec2f 	vec2f_sub(t_vec2f a, t_vec2f b);
t_vec2f 	vec2f_div_k(t_vec2f a, float k);
t_vec2f 	vec2f_div_vec(t_vec2f a, t_vec2f b);
t_vec2f 	vec2f_mul_vec(t_vec2f a, t_vec2f b);
t_vec2f 	vec2f_mul_k(t_vec2f a, float k);
t_vec2f 	vec2f_normalize(t_vec2f a);
t_vec2f 	vec2f_apply_fn_float(t_vec2f a, float(*fn)(float k));
t_vec2f 	vec2f_apply_fn_int(t_vec2f a, int(*fn)(float k));

/*
** ------- operations returning scalars
** dotprod -> returns the scalar value resulting from the dot product of a and b  
** dist_origin -> returns the distance between the vec3f a and the origin (implicitly a vec3f)
** dist_ab -> returns the distance between the a and b vectors
*/

float		vec3f_dotprod(t_vec3f a, t_vec3f b);
float		vec3f_dist_origin(t_vec3f a);
float		vec3f_dist_ab(t_vec3f a, t_vec3f b);

float		vec2f_dotprod(t_vec2f a, t_vec2f b);
float		vec2f_dist_origin(t_vec2f a);
float		vec2f_dist_ab(t_vec2f a, t_vec2f b);

// misc
float 		min(float a, float b);
float 		max(float a, float b);
float		sqr(float i);
float 		clamp(float x, float upper, float lower);
float		lerp(float a, float b, float f);
float		deg_to_rad(double radians);

#endif
