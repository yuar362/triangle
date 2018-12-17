#ifndef __TRIANGLE_H__
#define __TRIANGLE_H__

#include <array>

#include "Plane.h"

using point3d = std::array<double, 3>;
class Triangle
{
public:
    Triangle(const Vector3D & point1_, const Vector3D & point2_, const Vector3D& point3_);

	// �������� ��������� � ������� ����� �����������
	Plane getPlane() const;

	//��������� ����� �� ����� ������ ������������
	bool isPointInTriangle(const Vector3D & point_) const;
	
	// ����� ����� ����������� ������� � ������������ result_point_
	// ���� ����� ��� �� ����� false
	// ���� ������� � ����������� ����� � ����� ��������� � ������������, �� ����� ���� �� ����� �����������
	//first_point_, last_point_ - ������ � ����� �������
    bool getIntersection(const Vector3D & first_point_, const Vector3D & last_point_, Vector3D & intersection_point_);
private:
	Vector3D m_1st_point;
	Vector3D m_2nd_point;
	Vector3D m_3rd_point;
};

#endif //__TRIANGLE_H__
