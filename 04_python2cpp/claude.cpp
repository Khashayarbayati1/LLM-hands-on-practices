
#include <iostream>
#include <iomanip>
#include <chrono>

int main() {
    constexpr long long iterations = 100000000;
    constexpr double param1 = 4.0;
    constexpr double param2 = 1.0;

    auto start_time = std::chrono::high_resolution_clock::now();

    double result0 = 0.0;
    double result1 = 0.0;
    double result2 = 0.0;
    double result3 = 0.0;

    long long i = 1;
    for (; i + 3 <= iterations; i += 4) {
        double d0 = static_cast<double>(i);
        double d1 = static_cast<double>(i + 1);
        double d2 = static_cast<double>(i + 2);
        double d3 = static_cast<double>(i + 3);

        double j0a = d0 * param1 - param2;
        double j0b = d0 * param1 + param2;
        double j1a = d1 * param1 - param2;
        double j1b = d1 * param1 + param2;
        double j2a = d2 * param1 - param2;
        double j2b = d2 * param1 + param2;
        double j3a = d3 * param1 - param2;
        double j3b = d3 * param1 + param2;

        result0 += (1.0 / j0b - 1.0 / j0a);
        result1 += (1.0 / j1b - 1.0 / j1a);
        result2 += (1.0 / j2b - 1.0 / j2a);
        result3 += (1.0 / j3b - 1.0 / j3a);
    }

    double result = 1.0 + result0 + result1 + result2 + result3;

    for (; i <= iterations; ++i) {
        double d = static_cast<double>(i);
        double ja = d * param1 - param2;
        double jb = d * param1 + param2;
        result -= 1.0 / ja;
        result += 1.0 / jb;
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