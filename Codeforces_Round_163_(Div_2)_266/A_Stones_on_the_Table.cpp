#include <iostream>
#include <cmath>
#include <string>

using namespace std;

int main() {
    int n;
    cin >> n;
    string s;
    cin >> s;
    int count = 0;
    char start = s[0];
    for(int i = 1; i < n; i++){
        if(s[i] == start) count++;
        else start = s[i];
    }
    cout << count;
}