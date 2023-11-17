#include "Sinogram.h"



Sinogram::Sinogram()
{
	
	std::string name_tab[10] = { "a", "b", "c", "d","e", "f", "g", "h", "i", "j" };
	double m_middle_x[10] = { 0,0,0.22,-0.22,0,0,0,-0.08,0,0.06 };
	double m_middle_y[10] = { 0,-0.0184, 0,0,0.35,0.1,-0.1,-0.605,-0.605 ,-0.605 };
	double m_big_axis[10] = { 0.920,0.874,0.31,0.41,0.25,0.046,0.046 ,0.046,0.023,0.046 };
	double m_small_axis[10] = { 0.69,0.6624,0.11,0.16,0.21,0.046,0.046 ,0.023,0.023,0.023 };
	int m_angle[10] = { 90,90,72,108,90,0,0,0,0,90 };
	double m_parameter[10]{ 2.00,-0.98,-0.02,-0.02,0.01,0.01,0.01 ,0.01 ,0.01 ,0.01 };


	for (int i = 0; i < 10; ++i)
	{
		this->m_elipsa.push_back(Elipsa(name_tab[i], m_middle_x[i], m_middle_y[i], m_big_axis[i], m_small_axis[i], m_angle[i], m_parameter[i]));
	}

	


}


//implementation of equation Po(t) page 10

double Sinogram::proj_normalna(int i,int angle)
{    //2*roAB

	// 
	
	
	auto paramAB = m_elipsa.at(i).m_parameter * m_elipsa.at(i).m_big_axis * m_elipsa.at(i).m_small_axis;

	auto A_square = m_elipsa.at(i).m_big_axis   * m_elipsa.at(i).m_big_axis;

	auto B_square = m_elipsa.at(i).m_small_axis * m_elipsa.at(i).m_small_axis;

	auto a_suare_angle= A_square* pow(cos(angle), 2) + B_square * pow(sin(angle),2);
	auto P_t = (2 * paramAB / a_suare_angle) * sqrt(a_suare_angle - t);

	return P_t;
};
// implementation of equation Po'(t)
double Sinogram::proj_dowolna(int i, int angle)
{
	auto x_square = m_elipsa.at(i).m_middle_x * m_elipsa.at(i).m_middle_x;

	auto y_square = m_elipsa.at(i).m_middle_y * m_elipsa.at(i).m_middle_y;

	auto s = sqrt(x_square + y_square);

	auto gamma = atan2(m_elipsa.at(i).m_middle_y, m_elipsa.at(i).m_middle_x);

	auto angle = t - s * cos(gamma - angle);

	auto P_t_prim=proj_normalna(i, angle);

	return P_t_prim;


};

Sinogram& Sinogram::createSinogram(int widht, int height)
{
	for (int i = 0; i < widht; i++)
	{
		for (int j = 0; j < height; ++i)

		{
			for (int k = 0; k < 10; k++)
			{
				this->sinogram[i][j] += proj_dowolna(k, angle);
			}
         

		}

		
	}

	return *this;
}

	
	// finding max value in sinogram
	

Sinogram& Sinogram::sinogramScaling()
{
	int fp_max = this->sinogram[0][0];

	for (int i = 0; i < 256; ++i)
	{
		for (int j = 0; j < 300; ++j)
		{
			if (this->sinogram[i][j] > fp_max)
			{
				fp_max = this->sinogram[i][j];
			}


		}
	}
	// finding min value in simogram
	int fp_min = this->sinogram[0][0];
	for (int i = 0; i < 256; ++i)
	{
		for (int j = 0; j < 300; ++j)
		{
			if (this->sinogram[i][j] > fp_min)
			{
				fp_min = this->sinogram[i][j];
			}


		}
	}

	auto k = 4095 / (fp_max - fp_min);
	auto m = -fp_min * k;
	//recalculate the data
	for (int i = 0; i < 256; ++i)
	{
		for (int j = 0; j < 300; ++j)
		{
			if (this->sinogram[i][j] > fp_max)
			{
				this->sinogram[i][j] = this->sinogram[i][j] * k + m;
			}


		}
	}
}

bool Sinogram::saveSinogram()
{

	std::ofstream sinogram_bin("sinogrma.bin", std::ios::binary);
	if (!sinogram_bin)
	{
		std::cerr << "Nie otworzono pliku do zaoisu";
		return 1;
	}
	sinogram_bin.write(reinterpret_cast<const char*>(sinogram), sizeof(sinogram));

	return 0;
}




