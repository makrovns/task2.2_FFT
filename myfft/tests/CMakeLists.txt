set(SOURCE_EXE
tests.cpp
)

add_executable(FFT_tests ${SOURCE_EXE})

target_link_libraries(FFT_tests PUBLIC FFT_lib)

target_link_libraries(FFT_tests PUBLIC gtest_main)

set_property(TARGET FFT_tests PROPERTY FOLDER "FFT_tests")