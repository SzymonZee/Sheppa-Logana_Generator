#include "Elipsa.h"
#include <iostream>




Elipsa::Elipsa(std::string name, double middle_x, double  middle_y, double big_axis, double small_axis, double angle, double parameter) :m_name{ name }, m_middle_x{ middle_x },
m_middle_y{ middle_y }, m_big_axis{ big_axis }, m_small_axis{ small_axis }, m_angle{ angle }, m_parameter{ parameter }
{
	
};