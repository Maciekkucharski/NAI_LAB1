//
// Created by s20153 on 27.10.2021.
//

#ifndef NAI_NR2_LAB2_H
#define NAI_NR2_LAB2_H


#define PI 3.14159265

std::ostream& operator<<(std::ostream& o, std::vector<double> v);
std::vector<double> operator+(std::vector<double> a, std::vector<double> b);
std::vector<double> hill_climbing(std::function<double(std::vector<double>)> f, std::function<bool(std::vector<double>)> f_domain, std::vector<double> p0, int iterations, std::uniform_real_distribution<double> shift);
auto himmelblau_function = [](std::vector<double> v) {
    return pow((pow(v[0], 2) + v[1] - 11), 2) + pow((v[0] + pow(v[0], 2) - 7), 2);
};

auto himmelblau_domain = [](std::vector<double> v) {
    return (std::abs(v[0]) <= 5) && (std::abs(v[1]) <= 5);
};

auto levy_function = [](std::vector<double> v) {
    return pow(sin(3*PI*v[0]), 2) + pow(v[0]-1, 2) * (1 + pow(sin(3*PI*v[1]), 2)) + pow(v[1]-1, 2) * (1 + pow(sin(2*PI*v[1]), 2));
};

auto levy_domain = [](std::vector<double> v) {
    return (std::abs(v[0]) <= 10) && (std::abs(v[1]) <= 10);
};

std::vector<double> simulated_annealing(
        std::function<double(std::vector<double>)> f,
        std::function<bool(std::vector<double>)> f_domain,
        std::vector<double> p0,
        int iterations,
        std::function<double(int)> T,
        std::uniform_real_distribution<double> hop_range);

#endif //NAI_NR2_LAB2_H
