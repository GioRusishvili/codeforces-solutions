#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
using namespace std;

int main() {
    int t;
    cin >> t;
    for(int i = 0; i < t; i++){
        int n;
        cin >> n;
        int a[n]= {};
        for(int j = 0; j < n; j++) cin >> a[j];
        if(a[n-1] > a[0]) cout << "YES\n";
        else cout << "NO\n";
    }
}