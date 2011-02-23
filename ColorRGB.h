#ifndef _ColorRGB_h
#define _ColorRGB_h

#include <iostream>

class ColorRGB
{
	private:
		float red;
		float green;
		float blue;
	public:
		ColorRGB();
		ColorRGB(const float&, const float&, const float&);
		const float get_red() const;
		const float get_green() const;
		const float get_blue() const;
		void set_red(const float&);
		void set_blue(const float&);
		void set_green(const float&);
		void clamp_output(const float,const float, std::ostream&);
		ColorRGB& operator+=(const ColorRGB&);
		ColorRGB& operator-=(const ColorRGB&);
		ColorRGB& operator*=(const ColorRGB&);
		const ColorRGB operator+(const ColorRGB&) const;
		const ColorRGB operator-(const ColorRGB&) const;
		const ColorRGB operator*(const ColorRGB&) const;
		ColorRGB& operator*=(const float&);
		ColorRGB& operator/=(const float&);
		friend const ColorRGB operator*(const ColorRGB&, const float&);
		friend const ColorRGB operator*(const float&, const ColorRGB&);
		const ColorRGB operator/(const float&) const;
		friend std::ostream& operator<<(std::ostream& os,const ColorRGB&);
	};

#endif