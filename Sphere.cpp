#include "ColorRGB.h"
#include "Ray.h"
#include "Vector3D.h"
#include "Sphere.h"
#include "math.h"
#include <cassert>

//Creates a plane with surface normal and distance
Sphere::Sphere(const ColorRGB& cRGB, const float _radius, const Vector3D& Vect3D, const float refl_num)
{
	assert(refl_num >= 0 && refl_num <= 1);
	surface_color = new ColorRGB(cRGB);
	radius = _radius;
 	center = new Vector3D(Vect3D);
	reflectivity = refl_num;
}

//Deletes plane
Sphere::~Sphere()
{
	delete center;
}

//Finds intersection of ray and plane
const float Sphere::intersection(const Ray& Ray) const
{
	float t1,t2;
	
	getIntersections(Ray, t1, t2);
	
	if (t1>=0)
		return t1;
	else
		return NO_INTERSECT;
}

//returns surface normal of plane
const Vector3D Sphere::surface_normal(const Vector3D& Vect3D) const
{
	return (Vector3D(Vect3D-(*center))).normalize();
	//return (Vect3D-(*center))/(Vect3D-(*center)).magnitude2();
}

//finds all intersections
int Sphere::getIntersections(const Ray& ray, float& t1, float& t2) const
{
	float a = ray.get_direction()*ray.get_direction();
	float b = 2 * (ray.get_origin() * ray.get_direction() - ray.get_direction() * (*center));
	float c = ray.get_origin() * ray.get_origin() + (*center) * (*center) - 2 * (ray.get_origin() * (*center)) - (radius*radius);
	
	float x1 = (1/(2*a))*(-b+sqrtf(b*b-4*a*c));
	float x2 = (1/(2*a))*(-b-sqrtf(b*b-4*a*c));
	
	if (x1 < 0)
		x1 = -1;
	if (x2 < 0)
		x2 = -1;
		
	t1 = std::min(x1,x2);
	t2 = std::max(x1,x2);
	
	return 0;
}