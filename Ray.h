#ifndef _Ray_h_
#define _Ray_h_

class Vector3D;

class Ray
{
	private:
		Vector3D* origin;
		Vector3D* direction;
	public:
		Ray(const Vector3D&, const Vector3D&, bool=true);
		~Ray();
		const Vector3D get_origin() const;
		const Vector3D get_direction() const;
		const Vector3D getPointAt(const float&) const;
		const Ray reflect(const Vector3D&, const Vector3D&, const float=.0001) const;
};

#endif