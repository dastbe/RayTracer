#include <cassert>
#include "Vector3D.h"
#include "math.h"

//Generates generic vector at origin
Vector3D::Vector3D()
{
	(*this)[0] = 0;
	(*this)[1] = 0;
	(*this)[2] = 0;
}

//Generates vector at point (x,y,z)
Vector3D::Vector3D(const float& x, const float& y, const float& z)
{
	(*this)[0] = x;
	(*this)[1] = y;
	(*this)[2] = z;
}

//Dot Product
const float Vector3D::operator*(const Vector3D& Vect3D) const
{
	return ((*this)[0]*Vect3D[0])+((*this)[1]*Vect3D[1])+((*this)[2]*Vect3D[2]);
}

//Cross Product
const Vector3D Vector3D::operator%(const Vector3D& Vect3D) const
{
	return Vector3D( ((*this)[1]*Vect3D[2])-((*this)[2]*Vect3D[1]),
					((*this)[2]*Vect3D[0])-((*this)[0]*Vect3D[2]),
					((*this)[0]*Vect3D[1])-((*this)[1]*Vect3D[0])
					);
}

//Maps LHS onto RHS
const Vector3D Vector3D::project(const Vector3D& Vect3D) const
{
	return Vector3D(*this)*(((*this)*Vect3D)/(Vect3D*Vect3D));
}

//Magnitude squared
const float Vector3D::magnitude1() const
{
	return (*this)*(*this);
}

//Magnitude
const float Vector3D::magnitude2() const
{
	return sqrtf((*this)*(*this));
}

const Vector3D& Vector3D::normalize()
{
	(*this)/=(this)->magnitude2();
	return *this;
}

const Vector3D Vector3D::normalize() const
{
	return Vector3D(*this)/=(this)->magnitude2();
}

//returns a particular coordinate
const float& Vector3D::operator[](const int& i) const
{
	assert(i>-1 && i<3);
	return vect_arr[i];
}

//return a particular coordinate (not const)
float& Vector3D::operator[](const int& i)
{
	assert(i>-1 && i<3);
	return vect_arr[i];
}

//Adds the coordinates of one vector to another
Vector3D& Vector3D::operator+=(const Vector3D& Vect3D)
{
	(*this)[0] += Vect3D[0];
	(*this)[1] += Vect3D[1];
	(*this)[2] += Vect3D[2];
	
	return *this;
}

//Subtracts the coordinates of one vector from another
Vector3D& Vector3D::operator-=(const Vector3D& Vect3D)
{
	(*this)[0] -= Vect3D[0];
	(*this)[1] -= Vect3D[1];
	(*this)[2] -= Vect3D[2];
	
	return *this;
}

//Multiplies a vector by a scalar
Vector3D& Vector3D::operator*=(const float& scalar)
{
	vect_arr[0] *= scalar;
	vect_arr[1] *= scalar;
	vect_arr[2] *= scalar;
	
	return *this;
}

//Divides a vector by a scalar
Vector3D& Vector3D::operator/=(const float& scalar)
{
	vect_arr[0] /= scalar;
	vect_arr[1] /= scalar;
	vect_arr[2] /= scalar;
	
	return *this;
}

//Divides vector by a scalar
const Vector3D Vector3D::operator/(const float& scalar) const
{
	return Vector3D(*this)/=scalar;
}

//Multiples scalar and vector together
const Vector3D operator*(const Vector3D& Vect3D, const float& scalar)
{
	return Vector3D(Vect3D)*=scalar;
}

//Multiplies scalar and vector together (Commutative)
const Vector3D operator*(const float& scalar, const Vector3D& Vect3D)
{
	return Vector3D(Vect3D)*=scalar;
}

//Adds two vectors together
const Vector3D Vector3D::operator+(const Vector3D& Vect3D) const
{
	return Vector3D(*this)+=Vect3D;
}

//Subtracts two vectors from one another
const Vector3D Vector3D::operator-(const Vector3D& Vect3D) const
{
	return Vector3D(*this)-=Vect3D;
}

//Negates a vector
const Vector3D Vector3D::operator-() const {
	return Vector3D(-(*this)[0],-(*this)[1],-(*this)[2]);
}

//Outputs vector in a convenient format
std::ostream& operator<<(std::ostream& os, const Vector3D& Vect3D)
{
	return os << "(" << Vect3D[0] << "," << Vect3D[1] << "," << Vect3D[2] << ")";
}