#include <iostream>
#include <string>
#include <map>

int main() {
    using namespace std;
    int x = 44;
    auto y = 44;
    map<string, string> mapka = {{"x",    "y"},
                                 {"blaa", "aldsadsa"}};
    auto przetwarzaj = [](auto x) {
        return x + " ";
    };
    mapka["janek"] = "Nowak";
    for (auto[key, value] : mapka) {
        cout << "k:" << key << " = " << przetwarzaj(value) << endl;
    }
    return 0;
}
