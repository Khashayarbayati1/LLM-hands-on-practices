
#include <iostream>
#include <iomanip>
#include <chrono>

int main() {
    constexpr long long iterations = 100000000;
    constexpr double param1 = 4.0;
    constexpr double param2 = 1.0;

    auto start_time = std::chrono::high_resolution_clock::now();

    double result0 = 0.0, result1 = 0.0, result2 = 0.0, result3 = 0.0;
    
    long long i;
    for (i = 1; i <= iterations - 3; i += 4) {
        double d0 = i * param1;
        double d1 = (i + 1) * param1;
        double d2 = (i + 2) * param1;
        double d3 = (i + 3) * param1;
        
        result0 += 1.0 / (d0 + param2) - 1.0 / (d0 - param2);
        result1 += 1.0 / (d1 + param2) - 1.0 / (d1 - param2);
        result2 += 1.0 / (d2 + param2) - 1.0 / (d2 - param2);
        result3 += 1.0 / (d3 + param2) - 1.0 / (d3 - param2);
    }
    
    double result = 1.0 + result0 + result1 + result2 + result3;
    
    for (; i <= iterations; ++i) {
        double d = i * param1;
        result += 1.0 / (d + param2) - 1.0 / (d - param2);
    }
    
    result *= 4.0;

    auto end_time = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> elapsed = end_time - start_time;

    std::cout << std::fixed << std::setprecision(12);
    std::cout << "Result: " << result << "\n";
    std::cout << std::setprecision(6);
    std::cout << "Execution Time: " << elapsed.count() << " seconds\n";

    return 0;
}