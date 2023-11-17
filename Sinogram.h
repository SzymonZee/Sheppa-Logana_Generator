#pragma once
#include"Elipsa.h"
#include <vector>
#include <functional>
#include <fstream>
#include <cmath>

#ifndef M_PI_
#define M_PI_ 3.14159265358979323846
#endif
class Sinogram
{


public:
	Sinogram();

	int m_widht;
	int m_lenght;

	double proj_normalna(int i, double angle,int t);
	double proj_dowolna(int i, double angle, int t);
	

	Sinogram& createSinogram(int widht, int height);
    Sinogram& sinogramScaling();

	bool saveSinogram();

	double degreeToRad(double angle);
	double sinogram[300][256]{};
	std::vector<Elipsa>m_elipsa{};
	
};

