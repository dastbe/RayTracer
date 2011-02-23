#include "Vector3D.h"
#include "ColorRGB.h"
#include "Ray.h"
#include "SceneObject.h"
#include "Plane.h"
#include "Sphere.h"
#include "Scene3D.h"
#include "Camera.h"
#include "Light.h"
#include <iostream>

using namespace std;

int main() {	
	
	float w,x,y,z;
	
	std::cin >> w >> x >> y >> z;
	
	Plane p(ColorRGB(1,0,1), 0, Vector3D(0,1,0),w);
	Sphere s1(ColorRGB(1,0,0), .5, Vector3D(-1.2,.5,0),x);
	Sphere s2(ColorRGB(0,1,0), .5, Vector3D(0,.5,0),y);
	Sphere s3(ColorRGB(1,.5,.7), .5, Vector3D(1.2,.5,0),z);
	
	Light l1(Vector3D(-10,10,5), ColorRGB(.8,.8,.8));
	Light l2(Vector3D(5,3,5), ColorRGB(.3,.3,.3));
	Camera c(Vector3D(-1.5,1,3), Vector3D(-.3,.5,0));
	
	Scene3D scene;
	
	scene.add_object(&s1);
	scene.add_object(&s2);
	scene.add_object(&s3);
	scene.add_object(&p);
	
	scene.add_light(&l1);
	scene.add_light(&l2);
	
	scene.render(c, 10000, std::cout);
	
	/*Plane p(ColorRGB(.7,.7,.7), 0, Vector3D(1,0,0),1);
	Sphere s1(ColorRGB(1,.3,0), .5, Vector3D(1,0,0),1);
	Sphere s2(ColorRGB(.2,1,.4), .5, Vector3D(1,1,1),1);
	Sphere s3(ColorRGB(1,.7,0), .5, Vector3D(1,-1,-1),1);
	//Sphere s3(ColorRGB(0,0,1), .5, Vector3D(1.2,.5,0));
	//Sphere s4(ColorRGB(.5,.5,0), .25, Vector3D(-.5,.25,0));
	
	Light l1(Vector3D(5,0,0), ColorRGB(.7,.7,.7));
	Light l2(Vector3D(0,5,0), ColorRGB(.3,.3,.3));
	Camera c(Vector3D(3.75,-1,-.75), Vector3D(0,0,0)-Vector3D(3.75,-1,-.7));
	
	Scene3D scene;
	
	scene.add_object(&s1);
	scene.add_object(&s2);
	scene.add_object(&s3);
	//scene.add_object(&s4);
	scene.add_object(&p);
	
	scene.add_light(&l1);
	scene.add_light(&l2);
	
	scene.render(c, 2000, std::cout);*/
}