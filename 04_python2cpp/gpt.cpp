#include <iostream>
#include <iomanip>
#include <chrono>
#include <cstdint>

static inline double calculate(std::int64_t iterations, std::int64_t param1, std::int64_t param2) {
    const double c1 = static_cast<double>(param1);
    const double c2 = static_cast<double>(param2);
    double result = 1.0;

    std::int64_t i = 1;
    const std::int64_t block = 8;

    // Unrolled loop for performance
    for (; i + block - 1 <= iterations; i += block) {
        double base = c1 * static_cast<double>(i);

        // 1
        double j1 = base - c2;
        double j2 = base + c2;
        result += (-1.0 / j1) + (1.0 / j2);
        base += c1;

        // 2
        j1 = base - c2;
        j2 = base + c2;
        result += (-1.0 / j1) + (1.0 / j2);
        base += c1;

        // 3
        j1 = base - c2;
        j2 = base + c2;
        result += (-1.0 / j1) + (1.0 / j2);
        base += c1;

        // 4
        j1 = base - c2;
        j2 = base + c2;
        result += (-1.0 / j1) + (1.0 / j2);
        base += c1;

        // 5
        j1 = base - c2;
        j2 = base + c2;
        result += (-1.0 / j1) + (1.0 / j2);
        base += c1;

        // 6
        j1 = base - c2;
        j2 = base + c2;
        result += (-1.0 / j1) + (1.0 / j2);
        base += c1;

        // 7
        j1 = base - c2;
        j2 = base + c2;
        result += (-1.0 / j1) + (1.0 / j2);
        base += c1;

        // 8
        j1 = base - c2;
        j2 = base + c2;
        result += (-1.0 / j1) + (1.0 / j2);
    }

    // Remainder loop
    for (; i <= iterations; ++i) {
        double base = c1 * static_cast<double>(i);
        result += (-1.0 / (base - c2)) + (1.0 / (base + c2));
    }

    return result;
}

int main() {
    const std::int64_t iterations = 100000000;
    const std::int64_t param1 = 4;
    const std::int64_t param2 = 1;

    auto start = std::chrono::high_resolution_clock::now();
    double result = calculate(iterations, param1, param2) * 4.0;
    auto end = std::chrono::high_resolution_clock::now();

    std::chrono::duration<double> elapsed = end - start;

    std::cout.setf(std::ios::fixed);
    std::cout << std::setprecision(12) << "Result: " << result << '\n';
    std::cout << std::setprecision(6) << "Execution Time: " << elapsed.count() << " seconds\n";
    return 0;
}