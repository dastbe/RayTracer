#include "Ray.h"
#include "Vector3D.h"
#include <cassert>

//Sets ray to origin and direction vector with optional normalization
Ray::Ray(const Vector3D& _origin, const Vector3D& _direction, bool normalize) {
	origin = new Vector3D(_origin);
	direction = new Vector3D(_direction);
	
	if (normalize) {
		direction->normalize();
	}
}

//Deletes ray
Ray::~Ray()
{
	delete origin;
	delete direction;
}

//Returns origin vector
const Vector3D Ray::get_origin() const
{
	return *origin;
}

//Returns direction vector
const Vector3D Ray::get_direction() const
{
	return *direction;
}

//Gets vector along ray path at point t
const Vector3D Ray::getPointAt(const float& t) const
{
	assert(t >= 0);
	
	return get_origin()+(get_direction()*t);
}

//Reflects a way off an intersection point with a surface normal
const Ray Ray::reflect(const Vector3D& intersection, const Vector3D& normal, const float delta) const
{
	Vector3D dir_par = (-(*this).get_direction()).project(normal);
	Vector3D dir_refl = ((*this).get_direction())+(2*dir_par);
	
	return Ray(intersection+(dir_refl*delta), dir_par);
}