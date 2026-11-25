#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>
using namespace std;
int main() {
    int n;
    cin >> n;
    int run = 0;
    int prev = 0;
    int best = 0;
    for(int i = 0; i < n; i++){
        int a;
        cin >> a;
        if(a >= prev) {
            run++;
        }
        else run = 1;
        best = max(best, run);
        prev = a;
    }
    cout << best;
}