#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int main() {
    int n, q;
    cin >> n >> q;
    int a[n] = {};
    int b[n+1] = {};
    for(int i = 0; i < n; i++){
        cin >> a[i];
    }
    for(int i = 0; i < q; i++){
        int l, r;
        cin >> l >> r;
        b[l-1]++;
        b[r]--;
    }
    for(int i = 1   ; i < n; i++){
        b[i] = b[i] + b[i-1];
    }
    int size = sizeof(a) / sizeof(a[0]);
    sort(a, a + size, greater<int>());
    sort(b, b + size, greater<int>());
    long long sum = 0;
    for(int i = 0; i < n; i++){
        sum += (long long)a[i] * b[i];
    }
    cout << sum;
}