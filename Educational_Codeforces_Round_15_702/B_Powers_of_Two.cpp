#include <iostream>
#include <cmath>
#include <string>
#include <vector>
#include <unordered_map>
using namespace std;

int main() {
    int n;
    cin >> n;
    long long result = 0;
    unordered_map<int, int> m;
    for(int i = 0; i < n; i++){
        int a;
        cin >> a;
        for (int i = 0; i < 31; ++i) {
            long long power = 1LL << i;
            result += m[power - a];
        }
        m[a]++;
    }
    cout << result;
}