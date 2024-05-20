#include <ostream>
#include <fstream>
#include <cassert>
#include <iostream>
#include "VTKWriter.hpp"

void VTK::VTKStructuredWirte2D(const std::string &&filename, std::vector<std::vector<double>> &X, std::vector<std::vector<double>> &Y, const std::vector<std::string> &&scalars_name, const std::vector<std::vector<std::vector<double>>> &&scalars)
{
    assert(scalars_name.size() == scalars.size());
    std::ofstream file(filename);
    if (!file)
    {
        std::cerr << "Error: Cannot open file " << filename << std::endl;
        return;
    }
    file << "# vtk DataFile Version 3.0" << std::endl;
    file << "2D structured grid" << std::endl;
    file << "ASCII" << std::endl;
    file << "DATASET STRUCTURED_GRID" << std::endl;
    file << "DIMENSIONS " << X.size() << " " << Y[0].size() << " 1" << std::endl;
    // 输出坐标
    file << "POINTS " << X.size() * Y[0].size() << " float" << std::endl;
    for (size_t i = 0; i < X.size(); ++i)
    {
        for (size_t j = 0; j < X[0].size(); ++j)
        {
            file << X[i][j] << " " << Y[i][j] << " 0.0 ";
        }
    }
    file << std::endl;
    // 输出标量场数据，根据 scalars_name 和 scalars 的内容
    file << "POINT_DATA " << X.size() * Y[0].size() << std::endl;
    for (size_t s = 0; s < scalars.size(); ++s)
    {
        file << "SCALARS " << scalars_name[s] << " float" << std::endl;
        file << "LOOKUP_TABLE default" << std::endl;
        for (const auto &row : scalars[s])
        {
            for (const auto &val : row)
            {
                file << val << " ";
            }
        }
    }
    file.close();
}