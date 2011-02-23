#ifndef _SceneObject_h_
#define _SceneObject_h_

class ColorRGB;
class Ray;
class Vector3D;

#define NO_INTERSECT -1

class SceneObject
{
	protected:
		ColorRGB* surface_color;
		float reflectivity;
	public:
		SceneObject();
		SceneObject(const ColorRGB&, const float=0);
		~SceneObject();
		void set_color(const ColorRGB&);
		const ColorRGB get_color() const;
		void set_reflectivity(const float);
		const float get_reflectivity() const;
		virtual const float intersection(const Ray&) const;
		virtual const Vector3D surface_normal(const Vector3D&) const;
		const ColorRGB getColorAt(const Vector3D&) const;
};

#endif