#ifndef _Camera_h_
#define _Camera_h_

class Vector3D;
class Ray;

#define PI 3.14159265

class Camera
{
	private:
		Vector3D* location;
		Vector3D* direction;
		float fov; //radians
		Vector3D* camera_up;
		Vector3D* camera_right;
		float distance;
	public:
		Camera(const Vector3D&, const Vector3D&, float=(PI/3));
		Ray getRayForPixel(int,int,int) const;
};

#endif