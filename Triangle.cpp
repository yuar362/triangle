#include "Triangle.h"

#include "Plane.h"
#include <cassert>

//���������� ���� �� ����� ����������� � ��� ����� intersection_point_ 2� ��������
//first_segment1_ � vector1_ - ������ � ������ 1�� �������
//first_segment2_ � vector2_ - ������ � ������ 2�� �������
bool getIntersection(const Vector3D & first_segment1_, const Vector3D & vector1_, const Vector3D & first_segment2_, const Vector3D & vector2_,
						Vector3D & intersection_point_)
{
	//
}

Triangle::Triangle(const point3d & point1_, const point3d & point2_, const point3d & point3_) : 
	m_1st_point(point1_)
	,m_2nd_point(point2_)
	,m_3rd_point(point3_)
{
}

Plane Triangle::getPlane() const
{
	Vector3D vector1 = m_2nd_point - m_1st_point, vector2 = m_3rd_point - m_1st_point;
	return Plane{ vector1.cross(vector2), Vector3D(m_1st_point) };
}

bool Triangle::isPointInTriangle(const Vector3D & point_) const
{
	//���� ����� ����� ������ ������������, �� ��������� ������������ ��������, ����������� �� ���� ����� 
	//� �������� ��������, ������� � ���� �������
 	Vector3D vector1 = m_1st_point - point_, vector2 = m_2nd_point - point_, vector3 = m_3rd_point - point_;
	auto result_vector1 = vector1.cross(vector2);
	auto result_vector2 = vector2.cross(vector3);
	auto result_vector3 = vector3.cross(vector1);
	return (result_vector1 * result_vector2 >= 0) && (result_vector2 * result_vector3 >= 0);
}

bool Triangle::getIntersection(const point3d & first_point_, const point3d & last_point_, Vector3D & intersection_point_)
{
	Plane plane = getPlane();
	Vector3D first_vector(first_point_), last_vector(last_point_);
	Vector3D vector1 = first_vector - plane.m_point, vector2 = last_vector - plane.m_point;
	auto scal = vector1 * plane.m_normal;
	auto scal2 = vector2 * plane.m_normal;
	if (scal * scal2 > 0 )
	{
		// ������� ����� � ����� ������� �� ��������� ������������
		return false;
	}
	else if (scal == 0 && scal2 == 0)
	{
		// ������ ����� ������� � ����������� ����� � ����� ���������

		
	}
	else
	{
		// ������ ����� ������� ���������� ��������� ������������	
		// ��������� ��������� plane.m_normal * (x - plane.m_point) = 0
		// ��������� ������� x = segment * parameter + first_vector, ��� parameter ��������� �������� �� 0 �� 1 
		// ������� ����� ����������� � ������� ����� �� ��� ������ ������������� 
		auto segment = last_vector - first_vector;
		auto parameter = (plane.m_normal * (first_vector - plane.m_point)) / (plane.m_normal * segment);
		assert(parameter >= 0 && parameter <= 1);
		intersection_point_ = first_vector + segment * parameter;
		return isPointInTriangle(intersection_point_);
	}
}
