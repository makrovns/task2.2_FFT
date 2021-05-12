#pragma once
#include <vector>
#include <algorithm>
#include <complex>
#include <cmath>

constexpr double PI = 3.14159265;

using c_double = std::complex<double>;

namespace myfft
{
    std::vector<c_double> fft(std::vector<c_double>& in_signal);
    std::vector<c_double> inv_fft(const std::vector<c_double>& in_signal);
}