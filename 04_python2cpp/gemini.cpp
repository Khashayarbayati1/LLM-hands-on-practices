
#include <iostream>
#include <iomanip>
#include <chrono>

// The calculate function mirrors the Python logic.
// Using double ensures precision matches Python's float (which is C++ double).
// Passing param1 and param2 as doubles avoids repeated integer-to-float conversions in the loop.
// Clang's -Ofast -mcpu=native will automatically vectorize this loop using NEON instructions on Apple Silicon.
double calculate(int iterations, double param1, double param2) {
    double result = 1.0;
    
    // Iterate from 1 to iterations inclusive, exactly as range(1, iterations+1)
    // The compiler can unroll and pipeline this loop effectively.
    for (int i = 1; i <= iterations; ++i) {
        double j1 = i * param1 - param2;
        result -= (1.0 / j1);
        
        double j2 = i * param1 + param2;
        result += (1.0 / j2);
    }
    return result;
}

int main() {
    // Start high-resolution timer
    auto start_time = std::chrono::high_resolution_clock::now();

    // Execute the calculation
    // 100_000_000 iterations, params 4 and 1
    double result = calculate(100000000, 4.0, 1.0) * 4.0;

    // Stop timer
    auto end_time = std::chrono::high_resolution_clock::now();
    
    // Calculate elapsed time in seconds
    std::chrono::duration<double> duration = end_time - start_time;

    // Output formatted results
    std::cout << std::fixed << std::setprecision(12);
    std::cout << "Result: " << result << "\n";
    
    std::cout << std::fixed << std::setprecision(6);
    std::cout << "Execution Time: " << duration.count() << " seconds" << "\n";

    return 0;
}