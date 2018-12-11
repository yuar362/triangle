#include "Triangle.h"

#include "Plane.h"
#include <cassert>

//возвращает есть ли точка пересечения и эту точку intersection_point_ 2х отрезков
//first_point_segment1_ и vector1_ - начало и вектор 1го отрезка
//first_point_segment2_ и vector2_ - начало и вектор 2го отрезка
bool getIntersection2D(const Vector3D & first_point_segment1_, const Vector3D & vector1_, const Vector3D & first_point_segment2_, 
						const Vector3D & vector2_, Vector3D & intersection_point_)
{
	auto vector_first12 = first_point_segment2_ - first_point_segment1_;
	auto vector_last12 = vector_first12 + vector2_ - vector1_;
	if (vector_first12.cross(vector_last12) == Vector3D())
	{
		//отрезки лежат на одной прямой


		return false;
	}
	else
	{
		//в точке пересечения, если она есть, будет выполняться vector1_ * p1 + first_point_segment1_ = vector2_ * p2 + first_point_segment2_
		//где p1 и p2 c [0, 1]
		//vector2_ x vector1_ * p1 = vector2_ x (first_point_segment2_ - first_point_segment1_)
		auto vector21 = vector2_.cross(vector1_);
		if (vector21 == Vector3D())
		{
			//отрезки паралельны
			return false;
		}
		else
		{
			size_t non_zero_element;
			auto result = vector21.find([](double x) {return x != 0; }, non_zero_element);
			assert(result);
			auto rhs_vector = vector21.cross(vector_first12);
			auto p1 = rhs_vector[non_zero_element]/vector21[non_zero_element];
			if (p1 < 0 || p1 > 1)
				return false;
			bool is_intersect = true;
			intersection_point_ = vector1_ * p1 + first_point_segment1_;
			for (size_t i = 0; i < Vector3D::vector_size; ++i)
				if (vector21[i] * p1 != rhs_vector[i])
					is_intersect = false;
			return is_intersect;
		}
	}
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
	//если точка лежит внутри треугольника, то векторное произведение векторов, построенных из этой точки 
	//к соседним вершинам, смотрит в одну сторону
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
		// Отрезок лежит с одной стороны от плоскости треугольника
		return false;
	}
	else if (scal == 0 && scal2 == 0)
	{
		auto segment = last_vector - first_vector;
		// случай когда отрезок и треугольник лежат в одной плоскости
		//проверяем пересечение со всеми
		if (getIntersection2D(first_vector, segment, m_1st_point, m_2nd_point - m_1st_point, intersection_point_))
			return true;
		if (getIntersection2D(first_vector, segment, m_2nd_point, m_3rd_point - m_2nd_point, intersection_point_))
			return true;
		if (getIntersection2D(first_vector, segment, m_3rd_point, m_1st_point - m_3rd_point, intersection_point_))
			return true;

		return false;
	}
	else
	{
		// Случай когда отрезок пересекает плоскость треугольника	
		// уравнение плоскости plane.m_normal * (x - plane.m_point) = 0
		// уравнение отрезка x = segment * parameter + first_vector, где parameter принимает значение от 0 до 1 
		// находим точку пересечения и смотрим лежит ли она внутри треугольникаж 
		auto segment = last_vector - first_vector;
		auto parameter = (plane.m_normal * (plane.m_point - first_vector)) / (plane.m_normal * segment);
		assert(parameter >= 0 && parameter <= 1);
		intersection_point_ = first_vector + segment * parameter;
		return isPointInTriangle(intersection_point_);
	}
}
