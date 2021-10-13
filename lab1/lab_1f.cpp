#include <iostream>
#include <vector>

using namespace std;
void lab_1f() {

    srand(time(NULL));

    auto f2 = [](int value) {
        int ret = rand() % (value+1) + 1;
        return ret;
    };

    auto f1 = [](auto value) {
        double ret = abs(100 - value);
        return ret;
    };

    auto calculations = [](auto f1, auto f2, int iterator) {
        auto max_x = f2(0);
        auto max_y = f1(max_x);
        for (int i = 1; i < iterator; i++) {
            auto x = f2(i);
            auto y = f1(x);
            if (y > max_y){
                max_x = x;
                max_y = y;
            }
        }
        return make_pair(max_x,max_y);
    };

    auto result = calculations(f1, f2, 5);
    return;
}
