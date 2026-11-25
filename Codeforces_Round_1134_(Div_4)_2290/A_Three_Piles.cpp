#include <bits/stdc++.h>
using namespace std;
void solve(){
    int a, b, c;
    cin >> a >> b >> c;
    if(b - a == 1 && c - b == 1){
        cout << "YES" << endl;
        return;
    }
    cout << "NO" << endl;
    return;
}
int main() {
    int t;
    cin >> t;
    for(int i = 0; i < t; i++){
        solve();
    }
}