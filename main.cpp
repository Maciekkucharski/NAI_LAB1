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

pair<double, double> bit_converter_pair(vector<bool> binary_number) {
    long long sum1 = 0;
    long long sum2 = 0;
    for (int i = 0; i < 64; i++) {
        sum1 += (long long)binary_number[i]<<i;
    }
    for (int i = 64; i < 128; i++) {
        sum2 += (long long)binary_number[i]<<(i-64);
    }
    cout << sum1 << "       " << sum2;
    double result1= 5.0 * (sum1 / pow(2, 63));
    double result2= 5.0 * (sum2 / pow(2, 63));
    return {result1, result2};
}

vector<bool> bit_converter_vector(pair<double, double> number_pair){
    vector<bool> binary_number (128,0);
    double first_number = number_pair.first;
    double second_number = number_pair.second;
    long long x = (long long)((first_number * pow(2, 63)) / 5.0);
    long long y = (long long)((second_number * pow(2, 63)) / 5.0);
    cout << x << "      " << y;
    long long temp_x, temp_y;
    for (int i = 63; i >=0 ; i--) {
//        binary_number.push_back(x%2);
//        x/=2;
        temp_x = (x&1);
        x = x >> 1;
        binary_number[i] = temp_x;
        temp_y = (y&1);
        y = y >> 1;
        binary_number[i+64] = temp_y;
    }


//    for (int i = 0; i < 64 ; i++) {
//        binary_number.push_back(y%2);
//        y/=2;
//    }
    return binary_number;
}


auto himmelblau_function = [](std::vector<double> v) {
    return pow(pow((pow(v[0], 2) + v[1] - 11), 2) + pow((v[0] + pow(v[0], 2) - 7), 2),-1);
};


int main() {
    cout.precision(16);
    pair<double, double> test_pair = {-3.0, -2.123456789012345};
//    vector<bool> test = bit_converter_vector(test_pair);
//    pair<double, double> test_result = bit_converter_pair(test);
    pair<double, double> result = bit_converter_pair(bit_converter_vector(test_pair));
    cout << result.first << " <- num 1" << endl;
    cout << result.second<< " <- num 2" << endl;;




//    vector<bool> vec = {false,true,false,true,true,true,true,true};
//    vector<bool> vec = generate_random_bits(128);
//    pair<double, double> pair = bit_converter_pair(vec);
//    cout << pair.first<<endl;
//    cout << pair.second<<endl;
//    vector<bool> vec2 = bit_converter_vector(pair);
//    cout << endl;
//    for(int i=0;i<vec.size();i++){
//        cout << vec[i];
//    }
//    cout << endl;
//    for(int i=0;i<vec2.size();i++){
//        cout << vec2[i];
//    }
//    vector<double> converted_pair = {pair.first,pair.second};
//    cout << endl <<   himmelblau_function(converted_pair);


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