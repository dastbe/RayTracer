#ifndef _Sphere_h_
#define _Sphere_h_

#include "SceneObject.h"
class ColorRGB;
class Ray;
class Vector3D;

class Sphere: public SceneObject
{
	private:
		float radius;
		Vector3D* center;
	public:
		Sphere(const ColorRGB&, const float, const Vector3D&, const float=0);
		~Sphere();
		const float intersection(const Ray&) const;
		const Vector3D surface_normal(const Vector3D&) const;
		int getIntersections(const Ray&, float&, float&) const;
};

#endif