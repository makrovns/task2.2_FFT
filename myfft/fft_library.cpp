#include "fft_library.hpp"

namespace
{
    std::vector<c_double> main_fft(const std::vector<c_double>& in_signal, int64_t flag)
    {
        int size = in_signal.size();
        int cnt = 0;

        if (size == 1)
            return in_signal;

        std::vector<c_double> even(size / 2), odd(size / 2), out_signal(size);

        std::copy_if(in_signal.begin(), in_signal.end(), odd.begin(), [&cnt](c_double) {return !(cnt++ % 2); });
        std::copy_if(in_signal.begin(), in_signal.end(), even.begin(), [&cnt](c_double) {return (cnt++ % 2); });

        odd = main_fft(odd, flag);
        even = main_fft(even, flag);

        cnt = 0;

        for_each(out_signal.begin(), out_signal.end() - size / 2 , [&](c_double& elem)
            {
                elem = odd[cnt] + even[cnt] * std::exp(c_double(0, flag*2 * PI * cnt / size));
                ++cnt;
            });
    
        for_each(out_signal.begin() + size/2, out_signal.end(), [&](c_double& elem)
            {
                elem = odd[cnt - size/2 ] + even[cnt - size/2] * std::exp(c_double(0, flag*2 * PI * cnt / size));
                ++cnt;
            });
   
        return out_signal;
    }
}

std::vector<c_double> myfft::fft(std::vector<c_double>& in_signal)
{
    double lg_size = log(in_signal.size()) / log(2.0);
   
    if (lg_size - (int)(lg_size) != 0)
        in_signal.resize(1 << (int)lg_size + 1);
    
    auto out_put = main_fft(in_signal, 1);
    
    return out_put;
}

std::vector<c_double> myfft::inv_fft(const std::vector<c_double>& in_signal)
{
    auto out_put = main_fft(in_signal, -1);

    c_double size (out_put.size(), 0);

    std::for_each(out_put.begin(), out_put.end(), [&size](c_double& elem) {elem /= size; });

    return out_put;
}