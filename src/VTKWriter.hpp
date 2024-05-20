#pragma once
#include <string>
#include <ostream>
#include <vector>
#include <cassert>

/// @brief VTK �����ռ�
namespace VTK
{
    /// @brief ���2D�ṹ������VTK��ʽ�ļ�
    /// @param filename      �ļ���
    /// @param X             x����
    /// @param Y             y����
    /// @param scalars_name  ������������
    /// @param scalars       ������
    /// @author JLX
    /// @date  2024-5-20
    void VTKStructuredWirte2D(const std::string &&filename, std::vector<std::vector<double>> &X, std::vector<std::vector<double>> &Y,
                              const std::vector<std::string> &&scalars_name, const std::vector<std::vector<std::vector<double>>> &&scalars);
};