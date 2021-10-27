#include <functional>
#include <iomanip>
#include <iostream>
#include <list>
#include <random>
#include <vector>
#include <math.h>
#define PI 3.14159265
std::ostream& operator<<(std::ostream& o, std::vector<double> v)
{
    for (auto e : v) {
        o << std::fixed << std::setprecision(5) << " " << e;
    }
    return o;
}

std::vector<double> operator+(std::vector<double> a, std::vector<double> b)
{
    for (int i = 0; i < a.size(); i++) {
        a[i] += b[i];
    }
    return a;
}


std::vector<double> hill_climbing(std::function<double(std::vector<double>)> f, std::function<bool(std::vector<double>)> f_domain, std::vector<double> p0, int iterations, std::uniform_real_distribution<double> hop_range){
    std::random_device rd;
    std::mt19937 gen(rd());
    auto p = p0;
    std::uniform_int_distribution<> distrib(0, p.size()-1);
    if (!f_domain(p)) throw std::invalid_argument("The p0 point must be in domain");
    for (int i = 0; i < iterations; i++) {
        std::vector<double> p2;
        do{
            p2 = p;
            p2[distrib(gen)] += hop_range(gen);
        }while(!f_domain(p2));
        double y2 = f(p2);
        if (y2 < f(p)) {
            p = p2;
        }
    }
    return p;
}

std::vector<double> simulated_annealing(
        std::function<double(std::vector<double>)> f,
        std::function<bool(std::vector<double>)> f_domain,
        std::vector<double> p0,
        int iterations,
        std::function<double(int)> T,
        std::uniform_real_distribution<double> hop_range)
{
    std::random_device rd;
    std::mt19937 gen(rd());
    auto p = p0;
    auto p_global_best = p0;

    std::uniform_real_distribution<> u_k(0.0, 1.0);
    std::uniform_int_distribution<> distrib(0, p.size()-1);
    if (!f_domain(p)) throw std::invalid_argument("The p0 point must be in domain");

    for (int k = 0; k < iterations; k++) {
        std::vector<double> p2;
        do{
            p2 = p;
            p2[distrib(gen)] += hop_range(gen);
        }while(!f_domain(p2));
        double y2 = f(p2);
        if (y2 < f(p)) {
            p = p2;

        } else {
            double u = u_k(gen);
            if (u < exp(-abs(f(p2) - f(p)) / T(k))) {
                p = p2;
            } else {
            }
        }
        if (f(p) < f(p_global_best)) {
            p_global_best = p;
        }
    }
    return p_global_best;
}

