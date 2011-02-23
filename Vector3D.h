#ifndef _Vector3D_h_
#define _Vector3D_h_

#include <iostream>

class Vector3D
{
	private:
		float vect_arr[3];
	public:
		Vector3D();
		Vector3D(const float&,const float&,const float&);
		Vector3D& operator+=(const Vector3D&);
		Vector3D& operator-=(const Vector3D&);
		Vector3D& operator*=(const float&);
		Vector3D& operator/=(const float&);
		const float& operator[](const int&) const;
		float& operator[](const int&);
		const Vector3D project(const Vector3D&) const;
		const Vector3D operator+(const Vector3D&) const;
		const Vector3D operator-(const Vector3D&) const;
		const Vector3D operator/(const float&) const;
		const float operator*(const Vector3D&) const; //Dot Product
		const Vector3D operator%(const Vector3D&) const; //Cross Product
		const float magnitude1() const; //magnitude squared
		const float magnitude2() const; //magnitude
		const Vector3D& normalize(); //normalizes the vector
		const Vector3D normalize() const; //normalize on RHS
		const Vector3D operator-() const;
		friend const Vector3D operator*(const Vector3D&, const float&);
		friend const Vector3D operator*(const float&, const Vector3D&);
		friend std::ostream& operator<<(std::ostream& os, const Vector3D&);
};

#endif