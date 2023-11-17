#pragma once
#include <iostream>


class Elipsa
{
public:

	Elipsa(std::string name, double middle_x, double  middle_y, double big_axis, double small_axis, double angle, double parameter);
	std::string m_name;
	double m_middle_x;
	double m_middle_y;
	double m_big_axis;
	double m_small_axis;
	double m_angle;
	double m_parameter;



};


