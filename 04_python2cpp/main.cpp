
#include <iostream>
#include <iomanip>
#include <chrono>

// The Python loop performs result += (1/(i*p1+p2) - 1/(i*p1-p2)).
// This can be algebraically simplified to result += (-2*p2) / ((i*p1)^2 - p2^2)
// to reduce the number of arithmetic operations inside the hot loop. This
// mathematical reordering leads to a significant performance improvement and
// is a type of optimization enabled by flags like -Ofast.
double calculate(long long iterations, double param1, double param2) {
    double result = 1.0;
    
    // Pre-calculate constants outside the loop to avoid redundant computation.
    const double p1_squared = param1 * param1;
    const double p2_squared = param2 * param2;
    const double numerator = -2.0 * param2;

    // This simple loop structure is highly friendly to compiler vectorization.
    for (long long i = 1; i <= iterations; ++i) {
        // Explicitly cast loop counter to double for floating point arithmetic.
        const double i_d = static_cast<double>(i);
        result += numerator / (p1_squared * i_d * i_d - p2_squared);
    }
    return result;
}

int main() {
    // Use constexpr for constants known at compile-time.
    constexpr long long iterations = 100'000'000;
    constexpr double param1 = 4.0;
    constexpr double param2 = 1.0;

    // Use std::chrono for high-resolution timing.
    const auto start_time = std::chrono::high_resolution_clock::now();

    const double result = calculate(iterations, param1, param2) * 4.0;

    const auto end_time = std::chrono::high_resolution_clock::now();
    const std::chrono::duration<double> execution_time = end_time - start_time;

    // Set output stream formatting to match the Python script's output.
    std::cout << "Result: " << std::fixed << std::setprecision(12) << result << std::endl;
    std::cout << "Execution Time: " << std::fixed << std::setprecision(6) << execution_time.count() << " seconds" << std::endl;

    return 0;
}