#include "Vector3D.h"

#include <cmath>
#include <cassert>

Vector3D::Vector3D() : m_vector{ 0, 0, 0 }
{
}

Vector3D::Vector3D(double x_, double y_, double z_) : m_vector{x_, y_, z_}
{
}

Vector3D::Vector3D(const std::array<double, vector_size>& first_point_, const std::array<double, vector_size>& last_point_)
{
	for (size_t i = 0; i < vector_size; ++i)
	{
		m_vector[i] = last_point_[i] - first_point_[i];
	}
}

Vector3D::Vector3D(const std::array<double, vector_size>& point_) :
	m_vector(point_)
{
}

Vector3D Vector3D::cross(const Vector3D & rhs_) const
{
	return Vector3D(m_vector[1] * rhs_.m_vector[2] - m_vector[2] * rhs_.m_vector[1],
		m_vector[2] * rhs_.m_vector[0] - m_vector[0] * rhs_.m_vector[2],
		m_vector[0] * rhs_.m_vector[1] - m_vector[1] * rhs_.m_vector[0]);
}

double Vector3D::operator*(const Vector3D & rhs_) const
{
	double result = 0;
	for (size_t i = 0; i < vector_size; ++i)
		result += m_vector[i] * rhs_.m_vector[i];
	return result;
}

Vector3D Vector3D::operator*(double coeff_) const
{
	return Vector3D(coeff_ * m_vector[0], coeff_ * m_vector[1], coeff_ * m_vector[2]);
}

Vector3D & Vector3D::operator*=(double coeff_)
{
	*this = this->operator*(coeff_);
	return *this;
}

Vector3D Vector3D::operator+(const Vector3D & rhs_) const
{
	Vector3D result;
	for (size_t i = 0; i < vector_size; ++i)
		result.m_vector[i] = m_vector[i] + rhs_.m_vector[i];
	return result;
} 

Vector3D Vector3D::operator-(const Vector3D & rhs_) const
{
	Vector3D result;
	for (size_t i = 0; i < vector_size; ++i)
		result.m_vector[i] = m_vector[i] - rhs_.m_vector[i];
	return result;
}

bool Vector3D::operator==(const Vector3D & rhs_) const
{
	bool result = true;
	for (size_t i = 0; i < vector_size; ++i)
		if (m_vector[i] != rhs_.m_vector[i])
			result = false;
	return result;
}

double Vector3D::length() const
{
	return sqrt(this->operator*(*this)) ;
}

Vector3D Vector3D::norm() const
{
	auto coeff = this->length();
	coeff = 1 / coeff;
	return this->operator*(coeff);
}

double & Vector3D::operator[](size_t index_)
{
	assert(index_ < vector_size);
	return m_vector[index_];
}

const double & Vector3D::operator[](size_t index_) const
{
	assert(index_ < vector_size);
	return m_vector[index_];
}

bool Vector3D::find(std::function<bool(double)> condition_, size_t & index_) const
{
	for(size_t i = 0; i < vector_size; ++i)
	{
		if (condition_(m_vector[i]))
		{
			index_ = i;
			return true;
		}
	}
	return false;
}
