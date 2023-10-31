#include <iostream>
#include <vector>
using namespace std;

bool compare_string(string s, string t) {
    return s == t;
}

int main() {
    string s = "abcdef";
    string t = "abcef";

    bool same = compare_string(s, t);

    cout << same;
}