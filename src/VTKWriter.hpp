#pragma once
#include <string>
#include <ostream>
#include <vector>
#include <cassert>

/// @brief VTK 命名空间
namespace VTK
{
    /// @brief 输出2D结构化网格VTK格式文件
    /// @param filename      文件名
    /// @param X             x坐标
    /// @param Y             y坐标
    /// @param scalars_name  标量场的名称
    /// @param scalars       标量场
    /// @author JLX
    /// @date  2024-5-20
    void VTKStructuredWirte2D(const std::string &&filename, std::vector<std::vector<double>> &X, std::vector<std::vector<double>> &Y,
                              const std::vector<std::string> &&scalars_name, const std::vector<std::vector<std::vector<double>>> &&scalars);
};