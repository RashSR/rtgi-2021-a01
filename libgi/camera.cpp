#include "camera.h"

#include "random.h"

#include <fstream>
#include <iostream>

using namespace glm;
using namespace std;

//! Set up a camera ray using cam.up, cam.dir, cam.w, cam.h (see \ref camera::update_frustum)
ray cam_ray(const camera &cam, int x, int y, vec2 offset) {
	// todo: compute the camera rays for each pixel.
	// note: you can use the following function to export them as an obj model and look at them in blender.
	vec3 u = cross(cam.dir ,cam.up);
	vec3 v = cross(u, cam.dir);

	float px = (2*(x+0.5)/cam.w) - 1;
	float py = (2*(y+0.5)/cam.h) - 1;

	vec3 pxy = cam.pos + cam.dir + px * u + py * v;
	vec3 d = normalize(pxy - cam.pos);

	/*
	cout << "Camera Direction: ";
	cout << cam.dir;
	cout <<"\n";
	*/
	
	return ray(cam.pos, d);
}

void test_camrays(const camera &camera, int stride) {
	ofstream out("test.obj");
	int i = 1;
	for (int y = 0; y < camera.h; y += stride)
		for (int x = 0; x < camera.w; x += stride) {
			ray ray = cam_ray(camera, x, y);
			out << "v " << ray.o.x << " " << ray.o.y << " " << ray.o.z << endl;
			out << "v " << ray.d.x << " " << ray.d.y << " " << ray.d.z << endl;
			out << "l " << i++ << " " << i++ << endl;
		}
}


