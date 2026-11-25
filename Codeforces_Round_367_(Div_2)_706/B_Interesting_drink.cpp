#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>
using namespace std;
int main() {
    int n;
    cin >> n;
    int prices[n];
    for(int i = 0; i < n; i++){
        cin >> prices[i];
    }
    int q;
    cin >> q;
    int size = sizeof(prices) / sizeof(prices[0]);
    sort(prices, prices + size);
    for(int i = 0; i < q; i++){
        int m;
        cin >> m;
        cout << upper_bound(prices, prices + size, m) - prices << endl;
    }
}