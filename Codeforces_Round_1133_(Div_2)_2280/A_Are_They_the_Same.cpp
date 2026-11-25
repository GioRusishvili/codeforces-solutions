#include <bits/stdc++.h>
using namespace std;
void solve(){
    int n;
    long long k;
    cin >> n >> k;
    int target = k % 2;
    int ak = 0, bk = 0;
    for(int i = 0; i < n; i++){
        long long  x;
        cin >> x;
        if(x % 2 == target) ak++;
    }
    for(int i = 0; i < n; i++){
        long long  x;
        cin >> x;
        if(x % 2 == target) bk++;
    }
    if(ak <= bk){
        cout << "YES\n";
    } else {
        cout << "NO\n";
    }
}
int main() {
    int t;
    cin >> t;
    for(int i = 0; i < t; i++){
        solve();
    }
}