#ifndef __PLANE_H__
#define __PLANE_H__
#include "Vector3D.h"

struct Plane
{
	Vector3D m_normal;	//нормаль плоскости
	Vector3D m_point;	//точка плоскости
};

#endif // __PLANE_H__
