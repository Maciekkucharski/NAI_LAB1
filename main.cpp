#include <cmath>
#include <iostream>
#include <random>
#include <vector>

using namespace std;




vector<bool> generate_random_bits(int amount){
    vector<bool> bits = {};
    srand( time(NULL) );
    for(int i=0; i<amount; i++){
        bool randBool = rand() % 2;
        bits.push_back(randBool);
    }
    return bits;
}

pair<double, double> bit_converter_pair(vector<bool> binary_number, int split=64) {
    unsigned long long int sum1 = 0;
    unsigned long long int sum2 = 0;
    for (int i = 0; i < split; ++i) {
        if (binary_number[i] == true)
            sum1 += (unsigned long long int)1<<i;
    }
    for (int i = split; i < binary_number.size(); ++i) {
        if (binary_number[i] == true)
            sum2 += (unsigned long long int)1<<(i-split);
    }
    double result1 = double(sum1);
    double result2 = double(sum2);
    return {result1, result2};
}

vector<bool> bit_converter_vector (pair<unsigned long long int, unsigned long long int> number_pair){
    vector<bool> binary_number = {};
    unsigned long long int first_number = number_pair.first;
    unsigned long long int second_number = number_pair.second;
    for (int i = 0; i < sizeof(first_number)*4 ; ++i) {
        binary_number.push_back(first_number%2);
        first_number/=2;
    }

    for (int i = 0; i < sizeof(second_number)*4 ; ++i) {
        binary_number.push_back(second_number%2);
        second_number/=2;
    }
    return binary_number;
}

//double  fitness_f(pair<int,int> point_one, pair<int,int> point_two){
//    return sqrt((point_two.first-point_one.first)*(point_two.first-point_one.first)+(point_two.second-point_one.second)*(point_two.second-point_one.second));
//}

auto himmelblau_function = [](std::vector<double> v) {
    return pow(pow((pow(v[0], 2) + v[1] - 11), 2) + pow((v[0] + pow(v[0], 2) - 7), 2),-1);
};


int main() {
    cout.precision(40);
//    vector<bool> vec = {false,true,false,true,true,true,true,true};
    vector<bool> vec = generate_random_bits(64);
    pair<double, double> pair = bit_converter_pair(vec,32);
    cout << pair.first<<endl;
    cout << pair.second<<endl;
    vector<bool> vec2 = bit_converter_vector(pair);
    cout << endl;
    for(int i=0;i<vec.size();i++){
        cout << vec[i];
    }
    cout << endl;
    for(int i=0;i<vec2.size();i++){
        cout << vec2[i];
    }
    vector<double> converted_pair = {pair.first,pair.second};
    cout << endl <<   himmelblau_function(converted_pair);


}

//zad 2/3
//random_device rd;
//mt19937 mt_generator(rd());
//int input = 0;
//cout << " 1: himmelblau, 2:Levy" << endl;
//cin >> input;
//double bottom, top;
//cout << "Bottom Range:" << endl;
//cin >> bottom;
//cout << "Top Range:" << endl;
//cin >> top;
//uniform_real_distribution<double> hop_range = uniform_real_distribution<double>(bottom, top);
//int iterations;
//cout << "Iterations:" << endl;
//cin >> iterations;
//
//
//if (input == 1) {
//uniform_real_distribution<> random(-5, 5);
//vector<double> p0 = {
//        random(mt_generator),
//        random(mt_generator),
//};
//cout << p0[0]<< "|" << p0[1] <<endl;
//
//auto result = simulated_annealing(himmelblau_function, himmelblau_domain, p0, iterations, [](int k) { return 1000.0 / k; }, hop_range);
//cout << "f(" << result << ") = " << himmelblau_function(result) << endl;
//
//auto point = hill_climbing(himmelblau_function, himmelblau_domain, p0, iterations, hop_range);
//cout << "f(" << point << ") = " << himmelblau_function(point) << endl;
//
//} else {
//uniform_real_distribution<> random(-10, 10);
//vector<double> p0 = {
//        random(mt_generator),
//        random(mt_generator),
//};
//cout << p0[0]<< "|" << p0[1] <<endl;
//auto result = simulated_annealing(himmelblau_function, himmelblau_domain, p0, iterations, [](int k) { return 1000.0 / k; }, hop_range);
//cout << "f(" << result << ") = " << himmelblau_function(result) << endl;
//
//auto point = hill_climbing(levy_function, levy_domain, p0, iterations, hop_range);
//cout << "f(" << point << ") = " << levy_function(point) << endl;
//
//}