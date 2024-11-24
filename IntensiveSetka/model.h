#pragma once
#include <vector>
#include <complex>
//проверить как используется расстояние между соседями
class setka
{
	double lyamda;
	//коэффициенты для длин волн
	double R;
	double Ksosed;
	double stepSource;
	int maxX;
	int maxY;
	std::vector<std::vector<double>> intensive;

public:
	std::complex<double> CalcA(int x, int y, std::pair<double, double> pos_antenna);

	void CalcIntensive(std::vector<std::pair<double, double>>& ants);

	void Main(double l, double rad, double Ksos, int maxx, int maxy, double step, std::vector<std::pair<double, double>>& ants);

	std::vector<std::vector<double>> GetIntensive();
};