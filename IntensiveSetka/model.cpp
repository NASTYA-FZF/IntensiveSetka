#include "pch.h"
#define _USE_MATH_DEFINES
#define p2(x) ((x) * (x))
#include "model.h"
using namespace std;

std::complex<double> setka::CalcA(int x, int y, std::pair<double, double> pos_antenna)
{
    double z = sqrt(p2(R) - p2(x) - p2(y));
    double r = sqrt(p2(x - pos_antenna.first) + p2(y - pos_antenna.second) + p2(z)) * lyamda;
    double arg = -2. * M_PI * r / lyamda;
    return std::complex<double>(cos(arg) / r, sin(arg) / r);
}

void setka::CalcIntensive()
{
    complex<double> sum;
    complex<double> nulls(0, 0);
    intensive.resize(maxY);
    for (int y = 0; y < maxY; y++)
    {
        intensive[y].resize(maxX);
        for (int x = 0; x < maxX; x++)
        {
            if (p2(x) + p2(y) > p2(R))
                intensive[y][x] = 0;
            else
            {
                sum = nulls;
                for (int ant = 0; ant < antenna.size(); ant++)
                {
                    sum += CalcA(x, y, antenna[ant]);
                }
                intensive[y][x] = sqrt(p2(sum.real()) + p2(sum.imag()));
            }
        }
    }
}
