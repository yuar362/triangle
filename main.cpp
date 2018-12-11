#include <iostream>
#include "Triangle.h"

int main()
{
	double pnt1_x, pnt1_y, pnt1_z, pnt2_x, pnt2_y, pnt2_z, pnt3_x, pnt3_y, pnt3_z;
	double segment_x1, segment_y1, segment_z1, segment_x2, segment_y2, segment_z2;
	std::cout << "Triangle:" << std::endl;
	std::cout << "1st point: x, y, z = ";
	std::cin >> pnt1_x >> pnt1_y >> pnt1_z;
	std::cout << "2nd point: x, y, z = ";
	std::cin >> pnt2_x >> pnt2_y >> pnt2_z;
	std::cout << "3rd point: x, y, z = ";
	std::cin >> pnt3_x >> pnt3_y >> pnt3_z;
	std::cout << "Segment:" << std::endl;
	std::cout << "1st point: x, y, z = ";
	std::cin >> segment_x1 >> segment_y1 >> segment_z1;
	std::cout << "2nd point: x, y, z = ";
	std::cin >> segment_x2 >> segment_y2 >> segment_z2;
	Vector3D intersection_point;
	Triangle triangle({ pnt1_x, pnt1_y, pnt1_z }, { pnt2_x, pnt2_y, pnt2_z }, { pnt3_x, pnt3_y, pnt3_z });
	if (!triangle.getIntersection({ segment_x1, segment_y1, segment_z1 }, { segment_x2, segment_y2, segment_z2 }, intersection_point))
		std::cout << "There is no intersection!" << std::endl;
	else
		std::cout << "intersection point: " << intersection_point[0] << " " << intersection_point[1] << " " << intersection_point[2];
	system("pause");
	return 0;
}