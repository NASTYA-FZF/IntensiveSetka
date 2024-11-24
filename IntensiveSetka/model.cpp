#include "pch.h"
#define _USE_MATH_DEFINES
#define p2(x) ((x) * (x))
#include "model.h"
using namespace std;

std::complex<double> setka::CalcA(int x, int y, std::pair<double, double> pos_antenna)
{
    double z = sqrt(p2(R) - p2(x) - p2(y)) * stepSource;
    double r = sqrt(p2(x * stepSource - pos_antenna.first * Ksosed * lyamda) + p2(y * stepSource - pos_antenna.second * Ksosed * lyamda) + p2(z));
    double arg = 2. * M_PI * r / lyamda;
    auto com = std::complex<double>(cos(arg) / r, -sin(arg) / r);
    return com;
}

void setka::CalcIntensive(std::vector<std::pair<double, double>>& antenna)
{
    complex<double> sum;
    complex<double> nulls(0, 0);
    int itx = 0;
    int ity = 0;
    intensive.resize(maxY);
    for (int y = -floor(maxY / 2); y < floor(maxY / 2); y++)
    {
        itx = 0;
        intensive[ity].resize(maxX);
        for (int x = -floor(maxX / 2); x < floor(maxX / 2); x++)
        {
            if (p2(x) + p2(y) > p2(R))
                intensive[ity][itx] = 0;
            else
            {
                sum = nulls;
                for (int ant = 0; ant < antenna.size(); ant++)
                {
                    sum += CalcA(x, y, antenna[ant]);
                }
                intensive[ity][itx] = sqrt(p2(sum.real()) + p2(sum.imag()));
            }
            itx++;
        }
        ity++;
    }
}

void setka::Main(double l, double rad, double Ksos, int maxx, int maxy, double step, std::vector<std::pair<double, double>>& ants)
{
    lyamda = l; R = rad; Ksosed = Ksos; maxX = maxx; maxY = maxy; stepSource = step;
    CalcIntensive(ants);
}

std::vector<std::vector<double>> setka::GetIntensive()
{
    return intensive;
}
