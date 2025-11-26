
#include <iostream>
#include <iomanip>
#include <chrono>

// Calculates the series using an algebraically simplified, faster formula.
// The original loop body is: result += (1.0 / (i * p1 + p2)) - (1.0 / (i * p1 - p2));
// This simplifies to: result += -2.0 * p2 / ((i * p1)^2 - p2^2);
// This transformation reduces two expensive divisions to one per iteration.
double calculate(const long long iterations, const double param1, const double param2) {
    double result = 1.0;
    
    const double p1_sq = param1 * param1;
    const double p2_sq = param2 * param2;
    const double term_numerator = -2.0 * param2;

    for (long long i = 1; i <= iterations; ++i) {
        const double i_d = static_cast<double>(i);
        result += term_numerator / (p1_sq * i_d * i_d - p2_sq);
    }
    return result;
}

int main() {
    std::ios_base::sync_with_stdio(false);

    const long long iterations = 100'000'000;
    const double param1 = 4.0;
    const double param2 = 1.0;

    const auto start_time = std::chrono::high_resolution_clock::now();

    const double result = calculate(iterations, param1, param2) * 4.0;

    const auto end_time = std::chrono::high_resolution_clock::now();
    const std::chrono::duration<double> elapsed = end_time - start_time;

    std::cout << std::fixed << std::setprecision(12);
    std::cout << "Result: " << result << '\n';
    std::cout << std::setprecision(6);
    std::cout << "Execution Time: " << elapsed.count() << " seconds\n";

    return 0;
}