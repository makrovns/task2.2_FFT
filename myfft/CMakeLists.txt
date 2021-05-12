set(SOURCES_LIB
fft_library.hpp
fft_library.cpp

)

add_library(FFT_lib ${SOURCES_LIB})

target_include_directories(FFT_lib PUBLIC ${CMAKE_CURRENT_LIST_DIR})

source_group(TREE ${CMAKE_CURRENT_LIST_DIR} FILES ${SOURCES_LIB})

set_property(TARGET FFT_lib PROPERTY FOLDER "FFT_library")

# включаем в сборку проекnа подпроект с тестами
add_subdirectory(tests)