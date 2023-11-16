#pragma once
#include"Elipsa.h"
#include <vector>
class Sinogram
{



	Sinogram();




	


	int m_widht;
	int m_lenght;
	double proj_normalna(int i, int angle);
	double proj_dowolna(int i, int angle);
	uint16_t sinogram[300][256];
	std::vector<Elipsa>m_elipsa{};
	Sinogram& createSinogram(int widht, int height);

	void saveSinogram();

	Sinogram::scaling

};

