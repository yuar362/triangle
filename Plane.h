#ifndef __PLANE_H__
#define __PLANE_H__
#include "Vector3D.h"

struct Plane
{
	Vector3D m_normal;	//������� ���������
	Vector3D m_point;	//����� ���������
};

#endif // __PLANE_H__
