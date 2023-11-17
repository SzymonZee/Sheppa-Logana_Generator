#pragma once
#include"Elipsa.h"
#include <vector>
#include <functional>
#include <fstream>
class Sinogram
{


public:
	Sinogram();

	int m_widht;
	int m_lenght;

	double proj_normalna(int i, int angle);
	double proj_dowolna(int i, int angle);
	

	Sinogram& createSinogram(int widht, int height);
    Sinogram& sinogramScaling();

	bool saveSinogram();

	uint16_t sinogram[300][256];
	std::vector<Elipsa>m_elipsa{};
	
};

