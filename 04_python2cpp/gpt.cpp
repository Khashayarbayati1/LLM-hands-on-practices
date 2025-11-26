#include <iostream>
#include <iomanip>
#include <chrono>
#include <cstdint>

static inline double calculate(int64_t iterations, int64_t param1, int64_t param2) {
    double result = 1.0;
    for (int64_t i = 1; i <= iterations; ++i) {
        double j = static_cast<double>(i) * static_cast<double>(param1) - static_cast<double>(param2);
        result -= 1.0 / j;
        j = static_cast<double>(i) * static_cast<double>(param1) + static_cast<double>(param2);
        result += 1.0 / j;
    }
    return result;
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);

    const int64_t iterations = 100000000;
    const int64_t param1 = 4;
    const int64_t param2 = 1;

    auto start_time = std::chrono::high_resolution_clock::now();
    double result = calculate(iterations, param1, param2) * 4.0;
    auto end_time = std::chrono::high_resolution_clock::now();

    std::chrono::duration<double> elapsed = end_time - start_time;

    std::cout << "Result: " << std::fixed << std::setprecision(12) << result << "\n";
    std::cout << "Execution Time: " << std::fixed << std::setprecision(6) << elapsed.count() << " seconds\n";
    return 0;
}