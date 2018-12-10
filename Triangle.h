#ifndef __TRIANGLE_H__
#define __TRIANGLE_H__

#include <array>

#include "Plane.h"

using point3d = std::array<double, 3>;
class Triangle
{
public:
	Triangle(const point3d & point1_, const point3d & point2_, const point3d& point3_);

	// получить плоскость в которой лежит треугольник
	Plane getPlane() const;

	//провер€ет лежит ли точка внутри треугольника
	bool isPointInTriangle(const Vector3D & point_) const;
	
	// найти точку пересечени€ отрезка и треугольника result_point_
	// если точки нет то вернЄт false
	// если отрезок и треугольник лежат в одной плоскости и пересекаютс€, то вернЄт одну из точек пересечени€
	//first_point_, last_point_ - начало и конец отрезка
	bool getIntersection(const point3d & first_point_, const point3d & last_point_, Vector3D & intersection_point_);
private:
	Vector3D m_1st_point;
	Vector3D m_2nd_point;
	Vector3D m_3rd_point;
};

#endif //__TRIANGLE_H__
