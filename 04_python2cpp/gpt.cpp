#include <iostream>
#include <iomanip>
#include <chrono>
#include <cstdint>

inline double calculate(const int64_t iterations, const double p1, const double p2) {
    double result = 1.0;
    int64_t i = 1;
    const int64_t n = iterations;
    for (; i + 3 <= n; i += 4) {
        double a = i * p1;
        double j = a - p2; result -= 1.0 / j; j = a + p2; result += 1.0 / j;

        a = (i + 1) * p1;
        j = a - p2; result -= 1.0 / j; j = a + p2; result += 1.0 / j;

        a = (i + 2) * p1;
        j = a - p2; result -= 1.0 / j; j = a + p2; result += 1.0 / j;

        a = (i + 3) * p1;
        j = a - p2; result -= 1.0 / j; j = a + p2; result += 1.0 / j;
    }
    for (; i <= n; ++i) {
        double a = i * p1;
        double j = a - p2; result -= 1.0 / j;
        j = a + p2; result += 1.0 / j;
    }
    return result;
}

int main() {
    const int64_t iterations = 100000000;
    const double param1 = 4.0;
    const double param2 = 1.0;

    auto start_time = std::chrono::high_resolution_clock::now();
    double result = calculate(iterations, param1, param2) * 4.0;
    auto end_time = std::chrono::high_resolution_clock::now();

    std::chrono::duration<double> elapsed = end_time - start_time;

    std::cout.setf(std::ios::fixed);
    std::cout << "Result: " << std::setprecision(12) << result << '\n';
    std::cout << "Execution Time: " << std::setprecision(6) << elapsed.count() << " seconds\n";
    return 0;
}