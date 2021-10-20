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


std::vector<double> hill_climbing(std::function<double(std::vector<double>)> f, std::function<bool(std::vector<double>)> f_domain, std::vector<double> p0, int iterations, std::uniform_real_distribution<double> shift){
    std::random_device rd;
    std::mt19937 gen(rd());
    auto p = p0;
    std::uniform_int_distribution<> distrib(0, p.size()-1);
    if (!f_domain(p)) throw std::invalid_argument("The p0 point must be in domain");
    for (int i = 0; i < iterations; i++) {
        auto p2 = p;
        do{
            p2[distrib(gen)] += shift(gen);
        }while(f_domain(p2));
        double y2 = f(p2);
        if (y2 < f(p)) {
            p = p2;
        }
    }
    return p;
}

