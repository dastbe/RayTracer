#ifndef _Scene3D_h_
#define _Scene3D_h_

#include <vector>
#include <iostream>

class Camera;
class SceneObject;
class ColorRGB;
class Ray;
class Light;

class Scene3D
{
	private:
		std::vector<SceneObject*> objects;
		std::vector<Light*> lights;
	public:
		Scene3D();
		~Scene3D();
		void add_object(SceneObject* so);
		void add_light(Light* light);
		const ColorRGB traceRay(const Ray&,int=0) const;
		const SceneObject* findClosest(const Ray&, float&) const;
		void render(const Camera&, const int, std::ostream&);
};

#endif