#include "BSVL.h"

void	get_vec4_identity_matrix(t_vec4f mat[static 4]){
	mat[0] = (t_vec4f){1.,		0.,		0.,		0.};
	mat[1] = (t_vec4f){0.,		1.,		0.,		0.};
	mat[2] = (t_vec4f){0.,		0.,		1.,		0.};
	mat[3] = (t_vec4f){0.,		0.,		0.,		1.};
}

void	get_view_matrix(t_vec3f eye, t_vec3f center, t_vec3f up, t_vec4f mat[static 4])
{
	t_vec3f f;
	t_vec3f s;
	t_vec3f u;

	f = vec3f_normalize(vec3f_sub_vec(center, eye));
	s = vec3f_normalize(vec3f_crossprod(f, up));
	u = vec3f_crossprod(s, f);
	mat[0] = (t_vec4f){s.x,		s.y,	s.z,	0.};
	mat[1] = (t_vec4f){u.x,		u.y,	u.z,	0.};
	mat[2] = (t_vec4f){-f.x,	-f.y,	-f.z,	0.};
	mat[3] = (t_vec4f){0.,		0.,	0.,	1.};
}

void	get_arbitrary_rot_mat(t_vec3f axis, float angle, t_vec4f mat[static 4])
{
    axis = vec3f_normalize(axis);
    float s = sin(angle);
    float c = cos(angle);
    float oc = 1.0 - c;

    mat[0] = (t_vec4f){oc * axis.x * axis.x + c, oc * axis.x * axis.y - axis.z * s,  oc * axis.z * axis.x + axis.y * s,  0.0};
    mat[1] = (t_vec4f){oc * axis.x * axis.y + axis.z * s, oc * axis.y * axis.y + c,  oc * axis.y * axis.z - axis.x * s,  0.0};
    mat[2] = (t_vec4f){oc * axis.z * axis.x - axis.y * s, oc * axis.y * axis.z + axis.x * s,  oc * axis.z * axis.z + c,  0.0};
    mat[3] = (t_vec4f){0.0, 0.0, 0.0, 1.0};
}

void	get_translation_matrix(t_vec3f tr_vec, t_vec4f mat[static 4])
{
	mat[0] = (t_vec4f){1.,		0.,		0.,		0};
	mat[1] = (t_vec4f){0.,		1.,		0.,		0};
	mat[2] = (t_vec4f){0.,		0.,		1.,		0};
	mat[3] = (t_vec4f){tr_vec.x,	tr_vec.y,	tr_vec.z,	1.};
}

void	get_and_apply_translation_matrix(t_vec3f *target_addr, t_vec3f translation_vector)
{
	t_vec4f mat[4];
	t_vec3f res;

	get_translation_matrix(translation_vector, mat);
	res = vec3f_mul_mat4f(*target_addr, mat);
	*target_addr = res;
}

t_vec4f vec4f_mul_vec(t_vec4f a, t_vec4f b)
{
	t_vec4f new;

	new.x = a.x * b.x;
	new.y = a.y * b.y;
	new.z = a.z * b.z;
	new.w = a.w * b.w;
	return (new);
}

t_vec4f	vec4f_mul_mat4f(t_vec4f a, t_vec4f mat[static 4])
{
	t_vec4f		tmp;
	t_vec4f		res;

	tmp = vec4f_mul_vec(a, (t_vec4f){mat[0].x, mat[1].x, mat[2].x, mat[3].x});
	res.x = tmp.x + tmp.y + tmp.z + tmp.w;
	tmp = vec4f_mul_vec(a, (t_vec4f){mat[0].y, mat[1].y, mat[2].y, mat[3].y});
	res.y = tmp.x + tmp.y + tmp.z + tmp.w;
	tmp = vec4f_mul_vec(a, (t_vec4f){mat[0].z, mat[1].z, mat[2].z, mat[3].z});
	res.z = tmp.x + tmp.y + tmp.z + tmp.w;
	tmp = vec4f_mul_vec(a, (t_vec4f){mat[0].w, mat[1].w, mat[2].w, mat[3].w});
	res.w = tmp.x + tmp.y + tmp.z + tmp.w;
	return (res);
}
