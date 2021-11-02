#include <functional>
#include <iostream>
#include <list>
#include <random>
#include <vector>
#include "lab2/lab_2.hpp"
#include <chrono>
#define PI 3.14159265


using namespace std;

random_device rd;
mt19937 mt_generator(rd());


int main() {
    int input = 0;
    cout << " 1: himmelblau, 2:Levy" << endl;
    cin >> input;
    double bottom, top;
    cout << "Bottom Range:" << endl;
    cin >> bottom;
    cout << "Top Range:" << endl;
    cin >> top;
    uniform_real_distribution<double> hop_range = uniform_real_distribution<double>(bottom, top);
    int iterations;
    cout << "Iterations:" << endl;
    cin >> iterations;


    if (input == 1) {
        uniform_real_distribution<> random(-5, 5);
        vector<double> p0 = {
                random(mt_generator),
                random(mt_generator),
        };
        cout << p0[0]<< "|" << p0[1] <<endl;

        auto result = simulated_annealing(himmelblau_function, himmelblau_domain, p0, iterations, [](int k) { return 1000.0 / k; }, hop_range);
        cout << "f(" << result << ") = " << himmelblau_function(result) << endl;

        auto point = hill_climbing(himmelblau_function, himmelblau_domain, p0, iterations, hop_range);
        cout << "f(" << point << ") = " << himmelblau_function(point) << endl;

    } else {
        uniform_real_distribution<> random(-10, 10);
        vector<double> p0 = {
                random(mt_generator),
                random(mt_generator),
        };
        cout << p0[0]<< "|" << p0[1] <<endl;
        auto result = simulated_annealing(himmelblau_function, himmelblau_domain, p0, iterations, [](int k) { return 1000.0 / k; }, hop_range);
        cout << "f(" << result << ") = " << himmelblau_function(result) << endl;

        auto point = hill_climbing(levy_function, levy_domain, p0, iterations, hop_range);
        cout << "f(" << point << ") = " << levy_function(point) << endl;

    }

}
