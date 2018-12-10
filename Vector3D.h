#ifndef __VECTOR3D_H__
#define __VECTOR3D_H__
#include <array>

class Vector3D
{
public:
	static const int vector_size = 3;

	Vector3D();
	Vector3D(double x_, double y_, double z_);
	Vector3D(const std::array<double, vector_size> & first_point_, const std::array<double, vector_size> & last_point_);
	Vector3D(const std::array<double, vector_size> & point_);
	Vector3D cross(const Vector3D & rhs_) const;		//векторное произведение
	double operator*(const Vector3D & rhs_) const;	//скалярное произведение
	Vector3D operator*(double coeff_) const;
	Vector3D & operator*=(double coeff_);
	Vector3D operator+(const Vector3D & rhs_) const;
	Vector3D operator-(const Vector3D & rhs_) const;
	bool operator==(const Vector3D& rhs_) const;	
	double length() const;
	Vector3D norm() const;	//направление (вектор единичной длины)
	double& operator[](size_t index_);	
private:
	std::array<double, vector_size> m_vector;
};
#endif // !__VECTOR3D_H__
