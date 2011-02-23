#include "Vector3D.h"
#include "ColorRGB.h"
#include "Light.h"

Light::Light(const Vector3D& Vect3D, const ColorRGB& cRGB)
{
	position = new Vector3D(Vect3D);
	color = new ColorRGB(cRGB);
}

const Vector3D& Light::get_position() const
{
	return *position;
}

const ColorRGB& Light::get_color() const
{
	return *color;
}