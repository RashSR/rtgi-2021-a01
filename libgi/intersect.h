#pragma once

#include "rt.h"

struct aabb {
	vec3 min, max;
	aabb() : min(FLT_MAX), max(-FLT_MAX) {}
	void grow(vec3 v) {
		min = glm::min(v, min);
		max = glm::max(v, max);
	}
	void grow(const aabb &other) {
		min = glm::min(other.min, min);
		max = glm::max(other.max, max);
	}
};

// See Shirley (2nd Ed.), pp. 206. (library or excerpt online)
inline bool intersect(const triangle &t, const vertex *vertices, const ray &ray, triangle_intersection &info) {
	// todo
	vec3 a = vertices[t.a].pos;
	vec3 b = vertices[t.b].pos;
	vec3 c = vertices[t.c].pos;

	float A11 = a.x - b.x; float A12 = a.x - c.x; float A13 = ray.d.x;
	float A21 = a.y - b.y; float A22 = a.y - c.y; float A23 = ray.d.y;
	float A31 = a.z - b.z; float A32 = a.z - c.z; float A33 = ray.d.z;

	float beta11 = a.x - ray.o.x;
	float beta21 = a.y - ray.o.y;
	float beta31 = a.z - ray.o.z;

	float det = A11*(A22*A33 - A32*A23) + A12*(A31*A23 - A21*A33) + A13*(A21*A32 - A22*A31);

	float beta = (beta11*(A22*A33 - A32*A23) + beta21*(A31*A23 - A21*A33) + beta31*(A21*A32 - A22*A31)) / det;
	if(beta < 0 || beta > 0){
		return false;
	}

	float gamma = (A33*())/det;
	if(gamma < 0 || gamma >1){
		return false;
	}

	float tVal = 0;
	


	return false;
}	

