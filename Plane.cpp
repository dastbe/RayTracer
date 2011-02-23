#include "ColorRGB.h"
#include "Ray.h"
#include "Vector3D.h"
#include "Plane.h"
#include <cassert>

#include <iostream>

//Creates a plane with surface normal and distance
Plane::Plane(const ColorRGB& cRGB, const float _distance, const Vector3D& Vect3D, const float refl_num)
{
	assert(refl_num >= 0 && refl_num <= 1);
	surface_color = new ColorRGB(cRGB);
	distance = _distance;
	normal = new Vector3D(Vect3D);
	reflectivity = refl_num;
}

//Deletes plane
Plane::~Plane()
{
	delete normal;
}

//Finds intersection of ray and plane
const float Plane::intersection(const Ray& Ray) const
{
	float t = -(Ray.get_origin()*(this)->surface_normal(Vector3D())+distance)/(Ray.get_direction()*(this)->surface_normal(Vector3D()));
	
	if (t>=0)
		return t;
	else
		return NO_INTERSECT;
}

//returns surface normal of plane
const Vector3D Plane::surface_normal(const Vector3D& Vect3D) const
{
	return *normal;
}