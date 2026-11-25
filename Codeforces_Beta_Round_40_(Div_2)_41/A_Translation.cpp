#include <iostream>
#include <cmath>
#include <string>

using namespace std;

int main() {
    string s, t;
    cin >> s;
    cin >> t;
    int start = 0;
    int end = s.length() - 1;
    while (start < end) {
        std::swap(s[start], s[end]);
        start++;
        end--;
    }
    if(s == t) cout << "YES";
    else cout << "NO";
}