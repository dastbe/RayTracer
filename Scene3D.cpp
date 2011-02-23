#include "SceneObject.h"
#include "Camera.h"
#include "Light.h"
#include "Scene3D.h"
#include "Ray.h"
#include "ColorRGB.h"
#include "Vector3D.h"
#include "math.h"
#include <functional>
#include <cassert>
#include <algorithm>

#include <iostream>

struct delete_SO : public std::unary_function<SceneObject*,void>
{
	delete_SO() { }
	void operator() (SceneObject* s) { delete s; }	
};

struct delete_Light : public std::unary_function<Light*,void>
{
	delete_Light() { }
	void operator() (Light* l) { delete l; }	
};

Scene3D::Scene3D() { }

Scene3D::~Scene3D()
{
	std::for_each(objects.begin(), objects.end(), delete_SO());
	std::for_each(lights.begin(), lights.end(), delete_Light());
}

void Scene3D::add_object(SceneObject* SO)
{
	assert (SO != NULL);
	objects.push_back(SO);
}

void Scene3D::add_light(Light* l)
{
	assert (l != NULL);
	lights.push_back(l);
}

const ColorRGB Scene3D::traceRay(const Ray& ray, int depth) const
{

	float closest_t_value = NO_INTERSECT;
	const SceneObject* closest_object = findClosest(ray, closest_t_value);

	if (closest_object == 0)
		return ColorRGB(0,0,0);

	ColorRGB retColor(0,0,0);


	for (int i = 0; i < lights.size(); i++)
	{
		Vector3D normL = ((*lights[i]).get_position()-ray.getPointAt(closest_t_value)).normalize();
		Vector3D normN = (*closest_object).surface_normal(ray.getPointAt(closest_t_value));

		retColor += (*lights[i]).get_color()*(*closest_object).get_color()*std::max((normL*normN),float(0));
		
		if (depth < 6 && (*closest_object).get_reflectivity() > 0)
		{
				Ray reflected_ray = ray.reflect(ray.getPointAt(closest_t_value), (*closest_object).surface_normal(ray.getPointAt(closest_t_value)));
				ColorRGB reflection_color = traceRay(reflected_ray, depth+1);
				retColor+= (*closest_object).get_reflectivity()*reflection_color;
		}
		
	}	


	return retColor;
}

const SceneObject* Scene3D::findClosest(const Ray& ray, float& t_int) const
{
	t_int = NO_INTERSECT;
	int closest_obj_location = -1;
	
	for (int i = 0; i < objects.size(); i++)
	{
		float int_val = (*objects[i]).intersection(ray);
		if ((int_val < t_int || t_int == NO_INTERSECT) && int_val >= 0)
		{
			t_int = int_val;
			closest_obj_location = i;
		}
	}
	
	if (t_int >= 0)
		return objects[closest_obj_location];
	
	return 0;
}

void Scene3D::render(const Camera& camera, const int imgSize, std::ostream& os)
{
	
	os << "P3 " << imgSize << " " << imgSize << " " << 255 << "\n";
	
	for (int y = 0; y < imgSize; y++)
	{
		for (int x = 0; x < imgSize; x++)
		{
			ColorRGB pixelColor = traceRay(camera.getRayForPixel(x, y, imgSize));
			pixelColor*=255;
			pixelColor.clamp_output(0,255, std::cout);
			os << "\n";
		}
	}
	
}