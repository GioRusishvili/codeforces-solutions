#include <iostream>
#include <cmath>
using namespace std;

int main() {
    bool a[1000001] = {};
    for(int i = 2; i <= 1000000; i++){
        if(a[i]) continue;
        for(int j = 2*i; j <= 1000000; j += i){
            a[j] = true;
        }
    }
    int n;
    cin >> n;
    for(int i = 0; i < n; i++){
        long long x;
        cin >> x;
        long long r = sqrt(x);
        while (r * r > x) r--;
        while ((r + 1) * (r + 1) <= x) r++;
        if (r * r == x && r >= 2 && !a[r]) {
            cout << "YES" << "\n";
        } else {
            cout << "NO" << "\n";
        }
    }    
}