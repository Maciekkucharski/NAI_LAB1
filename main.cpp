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

pair<unsigned long long int, unsigned long long int> bit_converter_pair(vector<bool> binary_number, int split) {
    unsigned long long int sum1 = 0;
    unsigned long long int sum2 = 0;
    for (int i = 0; i < split; ++i) {
        if (binary_number[i] == true)
            sum1 += pow(2.0, i);
    }
    for (int i = split; i < binary_number.size(); ++i) {
        if (binary_number[i] == true)
            sum2 += pow(2.0, i-split);
    }
    return {sum1, sum2};
}

vector<bool> bit_converter_vector (pair<unsigned long long int, unsigned long long int> number_pair){
    vector<bool> binary_number = {};
    unsigned long long int first_number = number_pair.first;
    unsigned long long int second_number = number_pair.second;

    do{
        binary_number.push_back(first_number%2);
        first_number/=2;
    }while(first_number!=0);
    do{
        binary_number.push_back(second_number%2);
        second_number/=2;
    }while(second_number!=0);
    return binary_number;
}

double  fitness_f(pair<int,int> point_one, pair<int,int> point_two){
    return sqrt((point_two.first-point_one.first)*(point_two.first-point_one.first)+(point_two.second-point_one.second)*(point_two.second-point_one.second));
}
//

int main() {
//    vector<bool> vec = {false,true,true,true,true};
    vector<bool> vec = generate_random_bits(128);
    pair<unsigned long long int, unsigned long long int> pair = bit_converter_pair(vec,64);
//    cout << bit_converter_pair(vec,64).first<<endl;
//    cout << bit_converter_pair(vec,64).second<<endl;
    vector<bool> vec2 = bit_converter_vector(pair);
    for(int i=0;i<vec2.size();i++){
        cout << vec[i]<< vec2[i] << endl;
    }
//    cout << bit_converter_vector({,});


}

//
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