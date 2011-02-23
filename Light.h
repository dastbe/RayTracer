#ifndef _Light_h_
#define _Light_h_

class Vector3D;
class ColorRGB;

class Light
{
	private:
		Vector3D* position;
		ColorRGB* color;
	public:
		Light(const Vector3D&, const ColorRGB&);
		const Vector3D& get_position() const;
		const ColorRGB& get_color() const;
};

#endif