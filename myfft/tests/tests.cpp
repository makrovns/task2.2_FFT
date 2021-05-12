#include "fft_library.hpp"
#include <gtest/gtest.h>

TEST(myfft_tests, test_for_power_of_two)
{
    std::vector<c_double> input = { {0,5},{1,6},{2,4},{3,12},{4,2},{5,9},{6,0},{7,15},{8,8},{9,1},{10,11},{11,3},{12,4},{13,0},{14,1},{15,6} };
    size_t size_ = input.size();

    auto out_fft = myfft::fft(input);
    auto out_inv_fft = myfft::inv_fft(out_fft);


    for (size_t i = 0; i != size_; i++)
    {
        ASSERT_NEAR(input[i].real(), out_inv_fft[i].real(), 1e-4);
        ASSERT_NEAR(input[i].imag(), out_inv_fft[i].imag(), 1e-4);
    }   
    
}

TEST(myfft_tests, comparison_with_the_results_obtained_in_Matlab)
{
    std::vector<c_double> input = {{1,2}, {4,7}, {4,5}, {8,3}, {12,2}, {15,5}, {21,2}, {1,5}};
    size_t size_ = input.size();

    auto out_fft = myfft::fft(input);

    //Data was received in matlab
    std::vector<c_double> out_matlab = {{66,31}, {-26.7279, -17}, {-16, 7}, {4.7279,11.3431}, {10,-9}, {-1.2721, -17}, {-8,-13}, {-20.7279,22.6569}};

    for(size_t i = 0; i != size_; ++i)
    {
        ASSERT_NEAR(out_fft[i].real(), out_matlab[i].real(), 1e-3);
        ASSERT_NEAR(out_fft[i].imag(), out_matlab[i].imag(), 1e-3);
    }

}

TEST(myfft_tests, test_for_not_power_of_two)
{
    std::vector<c_double> input = { {7,3},{12,33},{1,23},{17,2},{11,14},{9,1},{19,7},{18,15},{11,21},{24,12},{30,18},
    {22,12},{14,15},{12,4},{8,18},{15,6}, {14,8}, {21,12} };
    size_t size_ = input.size();

    auto out_fft = myfft::fft(input);
    auto out_inv_fft = myfft::inv_fft(out_fft);


    for (size_t i = 0; i != size_; i++)
    {
        ASSERT_NEAR(input[i].real(), out_inv_fft[i].real(), 1e-4);
        ASSERT_NEAR(input[i].imag(), out_inv_fft[i].imag(), 1e-4);
    }
}

TEST(myfft_tests, test_for_only_real_part)
{
    std::vector<c_double> input = { {7,0},{12,0},{1,0},{17,0},{11,0},{9,0},{19,0},{18,0},{11,0},{24,0},{30,0},
    {22,0},{14,0} };
    size_t size_ = input.size();

    auto out_fft = myfft::fft(input);
    auto out_inv_fft = myfft::inv_fft(out_fft);

    for (size_t i = 0; i != size_; i++)
    {
        ASSERT_NEAR(input[i].real(), out_inv_fft[i].real(), 1e-4);
        ASSERT_NEAR(input[i].imag(), out_inv_fft[i].imag(), 1e-4);
    }
}

TEST(myfft_tests, test_for_only_image_part)
{
    std::vector<c_double> input = { {0,3},{0,33},{0,23},{0,2},{0,14},{0,1},{0,7},{0,15},{0,21},{0,12},{0,18},
    {0,12},{0,15} };
    size_t size_ = input.size();

    auto out_fft = myfft::fft(input);
    auto out_inv_fft = myfft::inv_fft(out_fft);

    for (size_t i = 0; i != size_; i++)
    {
        ASSERT_NEAR(input[i].real(), out_inv_fft[i].real(), 1e-4);
        ASSERT_NEAR(input[i].imag(), out_inv_fft[i].imag(), 1e-4);
    }
}

TEST(myfft_tests, test_for_zero)
{
    std::vector<c_double> input = { {0,0},{0,0},{0,0},{0,0},{0,0} };
    size_t size_ = input.size();

    auto out_fft = myfft::fft(input);
    auto out_inv_fft = myfft::inv_fft(out_fft);

    for (size_t i = 0; i != size_; i++)
    {
        ASSERT_NEAR(input[i].real(), out_inv_fft[i].real(), 1e-4);
        ASSERT_NEAR(input[i].imag(), out_inv_fft[i].imag(), 1e-4);
    }
}

TEST(myfft_tests, test_zero_in)
{
    std::vector<c_double> input;
    size_t size_ = input.size();

    auto out_fft = myfft::fft(input);
    auto out_inv_fft = myfft::inv_fft(out_fft);
    
    ASSERT_EQ(0, out_inv_fft[0].real());
    ASSERT_EQ(0, out_inv_fft[0].imag());
}

int main(int argc, char* argv[])
{
    ::testing::InitGoogleTest(&argc, argv);

    return RUN_ALL_TESTS();
}