#include "Camera.h"
#include "math.h"
#include "Vector3D.h"
#include "Ray.h"
#include <cassert>

Camera::Camera(const Vector3D& position, const Vector3D& look_at, float frameofview)
{
	location = new Vector3D(position);
	direction = new Vector3D((look_at-position).normalize());
	Vector3D up(0,1,0);
	camera_right = new Vector3D((*direction)%up);
	camera_up = new Vector3D((*camera_right)%(*direction));
	fov = frameofview;
	distance = .5 / tan(fov/2);
}

Ray Camera::getRayForPixel(int x, int y,int imgSize) const
{
	// dist = distance between camera location and the grid of pixels, as
	// computed earlier.  direction = normalized camera direction vector.
	
	assert(x>=0 && x < imgSize);
	assert(y>=0 && y < imgSize);
	Vector3D pixelDir = distance * (*direction) +
		(0.5 - (float) y / (float) (imgSize - 1)) * (*camera_up) +
		((float) x / (float) (imgSize - 1) - 0.5) * (*camera_right);

	Ray pixelRay((*location), pixelDir);
	return pixelRay;
}