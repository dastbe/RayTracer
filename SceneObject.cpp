#include "Vector3D.h"
#include "ColorRGB.h"
#include "Ray.h"
#include "SceneObject.h"
#include <cassert>

//Creates generic SceneObject with grey color
SceneObject::SceneObject()
{
	surface_color = new ColorRGB(.5,.5,.5);
	reflectivity = .5;
}

//Creates generic with color cRGB
SceneObject::SceneObject(const ColorRGB& cRGB, const float refl_num)
{
	assert(refl_num >= 0 && refl_num <= 1);
	surface_color = new ColorRGB(cRGB);
	reflectivity = refl_num;
}

//Deletes SceneObject
SceneObject::~SceneObject()
{
	delete surface_color;
}

//Sets color to cRGB
void SceneObject::set_color(const ColorRGB& cRGB)
{
	surface_color = new ColorRGB(cRGB);
}

//Returns color of object
const ColorRGB SceneObject::get_color() const
{
	return *surface_color;
}

void SceneObject::set_reflectivity(const float refl_num)
{
	assert(refl_num >= 0 && refl_num <= 1);
	reflectivity = refl_num;
}
const float SceneObject::get_reflectivity() const
{
	return reflectivity;
}

//Calculates intersection
const float SceneObject::intersection(const Ray&) const
{
	return NO_INTERSECT;
}

//Returns surface normal of object
const Vector3D SceneObject::surface_normal(const Vector3D&) const
{
	return Vector3D();
}

//gets Color at the point
const ColorRGB SceneObject::getColorAt(const Vector3D&) const
{
	return *surface_color;
}