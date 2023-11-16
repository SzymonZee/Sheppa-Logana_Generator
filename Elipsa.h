#pragma once
#include <iostream>


class Elipsa
{
public:

	Elipsa(std::string name, double middle_x, double  middle_y, double big_axis, double small_axis, int angle, double parameter);
	std::string m_name;
	double m_middle_x;
	double m_middle_y;
	double m_big_axis;
	double m_small_axis;
	int m_angle;
	double m_parameter;

	std::pair<double, double>m_middlePoints{};

};


std::string name_tab[10] = { "a", "b", "c", "d","e", "f", "g", "h", "i", "j" };
double m_middle_x[10] = { 0,0,0.22,-0.22,0,0,0,-0.08,0,0.06 };
double m_middle_y[10] = { 0,-0.0184, 0,0,0.35,0.1,-0.1,-0.605,-0.605 ,-0.605 };
double m_axis_h[10] = { 0.920,0.874,0.31,0.41,0.25,0.046,0.046 ,0.046,0.023,0.046 };
double m_axis_w[10] = { 0.69,0.6624,0.11,0.16,0.21,0.046,0.046 ,0.023,0.023,0.023 };
int m_angle[10] = { 90,90,72,108,90,0,0,0,0,90 };
double m_parameter[10]{ 2.00,-0.98,-0.02,-0.02,0.01,0.01,0.01 ,0.01 ,0.01 ,0.01 };