#include <bits/stdc++.h>
using namespace std;
void solve(){
    int n;
    cin >> n;
    string s;
    cin >> s;
    int count = 0;
    char cur = 'R';
    for (int i = 0; i < n; i++) {
        if (s[i] != cur) count++;
        cur = (s[i] == 'R') ? 'B' : 'R';
    }
    cout << count << endl;
}
int main() {
    int t;
    cin >> t;
    for(int i = 0; i < t; i++){
        solve();
    }
}