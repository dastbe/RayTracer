#ifndef _Plane_h_
#define _Plane_h_

#include "SceneObject.h"
class ColorRGB;
class Ray;
class Vector3D;

class Plane : public SceneObject
{
	private:
		float distance;
		Vector3D* normal;
	public:
		Plane(const ColorRGB&, const float, const Vector3D&, const float=0);
		~Plane();
		const float intersection(const Ray&) const;
		const Vector3D surface_normal(const Vector3D&) const;
};

#endif