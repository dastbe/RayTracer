#include "ColorRGB.h"
#include <cassert>

//Generates Color set to black
ColorRGB::ColorRGB()
{
	red = 0;
	green = 0;
	blue = 0;
}

//Generates Color with specified values (red, green, blue)
ColorRGB::ColorRGB(const float& red, const float& green, const float& blue)
{
	set_red(red);
	set_green(green);
	set_blue(blue);
}

//Get red component
const float ColorRGB::get_red() const
{
	return red;
}

//Get green component
const float ColorRGB::get_green() const
{
	return green;
}

//Get blue component
const float ColorRGB::get_blue() const
{
	return blue;
}

//Set red component
void ColorRGB::set_red(const float& _red)
{
	red = _red;
}

//Set green component
void ColorRGB::set_green(const float& _green)
{
	green = _green;
}

//Set blue component
void ColorRGB::set_blue(const float& _blue)
{
	blue = _blue;
}

void ColorRGB::clamp_output(const float minval, const float maxval, std::ostream& os)
{
	assert(minval < maxval);
	
	int int_red = int(red);
	int int_green = int(green);
	int int_blue = int(blue);
	
	if (red > maxval)
		int_red = int(maxval);
	if (red < minval)
		int_red = int(minval);
	if (green > maxval)
		int_green = int(maxval);
	if (green < minval)
		int_green = int(minval);
	if (blue > maxval)
		int_blue = int(maxval);
	if (blue < minval)
		int_blue = int(minval);
		
	os << int_red << " " << int_green << " " << int_blue;
}

//Adds one color to the LHS
ColorRGB& ColorRGB::operator+=(const ColorRGB& cRGB)
{
	red+=cRGB.get_red();
	green+=cRGB.get_green();
	blue+=cRGB.get_blue();
	
	return *this;	
}

//Subtracts one color from the LHS
ColorRGB& ColorRGB::operator-=(const ColorRGB& cRGB)
{
	red-=cRGB.get_red();
	green-=cRGB.get_green();
	blue-=cRGB.get_blue();
	
	return *this;
}

//Multiplies LHS by the RHS
ColorRGB& ColorRGB::operator*=(const ColorRGB& cRGB)
{
	red*=cRGB.get_red();
	green*=cRGB.get_green();
	blue*=cRGB.get_blue();
	
	return *this;
}

//Returns the sum of two colors
const ColorRGB ColorRGB::operator+(const ColorRGB& cRGB) const
{
	return ColorRGB(*this)+=cRGB;
}

//Returns the difference of two colors
const ColorRGB ColorRGB::operator-(const ColorRGB& cRGB) const
{
	return ColorRGB(*this)-=cRGB;
}

//Returns the product of two colors
const ColorRGB ColorRGB::operator*(const ColorRGB& cRGB) const
{
	return ColorRGB(*this)*=cRGB;
}

//Multiplies color by a scalar
ColorRGB& ColorRGB::operator*=(const float& scalar)
{
	red*=scalar;
	green*=scalar;
	blue*=scalar;
	
	return *this;
}

//Divides color by a scalar
ColorRGB& ColorRGB::operator/=(const float& scalar)
{
	red/=scalar;
	green/=scalar;
	blue/=scalar;
	
	return *this;
}

//Returns product of a color and a scalar
const ColorRGB operator*(const ColorRGB& cRGB, const float& scalar)
{
	return ColorRGB(cRGB)*=scalar;
}

//Returns product of a scalar and a color
const ColorRGB operator*(const float& scalar, const ColorRGB& cRGB)
{
	return ColorRGB(cRGB)*=scalar;
}

//Return quotient of a color and a scalar
const ColorRGB ColorRGB::operator/(const float& scalar) const
{
	return ColorRGB(*this)/=scalar;
}

//Outputs color to ostream as (r,g,b)
std::ostream& operator<<(std::ostream& os, const ColorRGB& cRGB)
{
	return os << "(" << cRGB.get_red() << "," << cRGB.get_green() << "," << cRGB.get_blue() << ")";
}