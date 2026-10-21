cmake_minimum_required(VERSION 3.21)
project(cpp_legacy_code)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(Boost REQUIRED COMPONENTS json)
find_package(OpenSSL REQUIRED)
find_package(Threads REQUIRED)

# Google Test
include(FetchContent)
FetchContent_Declare(
        googletest
        URL https://github.com/google/googletest/archive/refs/tags/v1.15.2.zip
)
FetchContent_MakeAvailable(googletest)

add_executable(cpp_legacy_code
        main.cpp
        src/ShippingCalculator.cpp
)

target_include_directories(cpp_legacy_code PRIVATE src)

target_link_libraries(cpp_legacy_code PRIVATE
        Boost::json
        OpenSSL::SSL
        OpenSSL::Crypto
        Threads::Threads
)

if (WIN32)
    target_compile_definitions(cpp_legacy_code PRIVATE _WIN32_WINNT=0x0601)
    target_link_libraries(cpp_legacy_code PRIVATE ws2_32 mswsock)
    target_link_options(cpp_legacy_code PRIVATE -static-libgcc -static-libstdc++ -static)

    add_custom_command(TARGET cpp_legacy_code POST_BUILD
            COMMAND ${CMAKE_COMMAND} -E copy_if_different
            $<TARGET_FILE:Boost::json>
            $<TARGET_FILE:OpenSSL::SSL>
            $<TARGET_FILE:OpenSSL::Crypto>
            $<TARGET_FILE_DIR:cpp_legacy_code>
    )
endif ()

# Enable testing
enable_testing()

# Create a library from the source code
add_library(shipping_calc_lib
        src/ShippingCalculator.cpp
        src/StandardShipping.cpp
        src/ExpressShipping.cpp
        src/OvernightShipping.cpp
        src/InternationalShipping.cpp
        src/SalesLedger.cpp
)

target_include_directories(shipping_calc_lib PUBLIC src)

target_link_libraries(shipping_calc_lib PUBLIC
        Boost::json
        OpenSSL::SSL
        OpenSSL::Crypto
        Threads::Threads
)

# Link the main executable to the library
target_link_libraries(cpp_legacy_code PRIVATE shipping_calc_lib)

# Add tests
add_executable(ShippingCalculatorTest test/ShippingCalculatorTest.cpp)
target_link_libraries(ShippingCalculatorTest PRIVATE
        shipping_calc_lib
        gtest
        gtest_main
)

add_test(NAME ShippingCalculatorTests COMMAND ShippingCalculatorTest)
