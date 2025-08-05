#include <iostream>
#include <chrono>
#include <iomanip>
#include "fastexp.h"

#include <cstdlib> // For rand() and RAND_MAX
#include <ctime>   // For time()

double generateRandom(double min, double max)
{
    // Generate a random integer between 0 and RAND_MAX
    double random_value = static_cast<double>(rand());

    // Scale and shift the value to the desired range
    return min + (random_value / RAND_MAX) * (max - min);
}

int main()
{
    const int n_trials = 100000000;
    std::vector<double> data(n_trials);
    std::vector<double> res(n_trials);
    for(int i = 0; i < n_trials; i++) {
        data[i] = generateRandom(1.0, 10.0);
    }

    auto t1 = std::chrono::high_resolution_clock::now();
    for (size_t i = 0; i < n_trials; ++i)
    {
        res[i] = std::exp(data[i]);
    }
    auto t2 = std::chrono::high_resolution_clock::now();
    long time = std::chrono::duration_cast<std::chrono::microseconds>(t2 - t1).count();

    double mean = static_cast<double>(time) / static_cast<double>(n_trials);
    std::cout << "std: " << std::setprecision(7) << mean << std::endl;

    time = 0;
    t1 = std::chrono::high_resolution_clock::now();
    for (size_t i = 0; i < n_trials; ++i)
    {
        res[i] = fastmath::exp(data[i]);
    }
    t2 = std::chrono::high_resolution_clock::now();
    time = std::chrono::duration_cast<std::chrono::microseconds>(t2 - t1).count();

    mean = static_cast<double>(time) / static_cast<double>(n_trials);
    std::cout << "fastmath: " << std::setprecision(7) << mean << std::endl;
    return 0;
}