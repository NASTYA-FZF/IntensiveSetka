#pragma once
#include <vector>
#include <complex>

class setka
{
	double lyamda;
	//коэффициенты для длин волн
	double R;
	double Ksosed;
	int maxX;
	int maxY;
	std::vector<std::pair<double, double>> antenna;
	std::vector<std::vector<double>> intensive;

public:
	std::complex<double> CalcA(int x, int y, std::pair<double, double> pos_antenna);

	void CalcIntensive();
};