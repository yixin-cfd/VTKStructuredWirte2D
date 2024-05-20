#include <iostream>
#include "VTKWriter.hpp"
using namespace std;

void test_all()
{
    std::cout << "test VTKStructuredWirte2D:" << std::endl;
    vector<vector<double>> X(5, vector<double>(5));
    vector<vector<double>> Y(5, vector<double>(5));
    for (int i = 0; i < X.size(); i++)
    {
        for (int j = 0; j < X[0].size(); j++)
        {
            X[i][j] = -5.0 + 10.0 * j / (X[0].size() - 1.0);
            Y[i][j] = 5 - 10.0 * i / (X.size() - 1.0);
        }
    }
    // ´òÓ¡X, Y
    cout << "X:" << endl;
    for (int i = 0; i < X.size(); i++)
    {
        for (int j = 0; j < X[0].size(); j++)
        {
            cout << X[i][j] << " ";
            if (j == X[0].size() - 1)
            {
                cout << endl;
            }
        }
    }
    cout << "Y:" << endl;
    for (int i = 0; i < Y.size(); i++)
    {
        for (int j = 0; j < Y[0].size(); j++)
        {
            cout << Y[i][j] << " ";
            if (j == Y[0].size() - 1)
            {
                cout << endl;
            }
        }
    }
    // v1
    auto v1 = vector<vector<double>>(X);
    int count = 1;
    for (int i = 0; i < Y.size(); i++)
    {
        for (int j = 0; j < Y[0].size(); j++)
        {
            v1[i][j] = count++;
        }
    }
    // ´òÓ¡v1
    cout << "v1:" << endl;
    for (int i = 0; i < v1.size(); i++)
    {
        for (int j = 0; j < v1[0].size(); j++)
        {
            cout << v1[i][j] << " ";
            if (j == v1[0].size() - 1)
            {
                cout << endl;
            }
        }
    }

    VTK::VTKStructuredWirte2D("t1.vtk",X, Y,{"v1"}, {v1});
}