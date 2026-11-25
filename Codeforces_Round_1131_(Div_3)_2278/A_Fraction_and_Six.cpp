#include <bits/stdc++.h>
using namespace std;
int main() {
    int t;
    cin >> t;
    vector<int> six(256, 0);
    six['s'] = 1;
    six['i'] = 1;
    six['x'] = 1;
    for(int i = 0; i < t; i++){
        int n, m;
        cin >> n >> m;
        string p, q;
        cin >> p;
        cin >> q;
        if(n-m != 3){
            cout << "NO\n";
            continue;
        }
        vector<int> freqP(256, 0);
        vector<int> freqQ(256, 0);
        for(char c : p) freqP[c]++;
        for(char c : q) freqQ[c]++;
        bool possible = true;
        for(int j = 0; j < 256; j++){
            int rem = freqP[j] - freqQ[j];
            if(rem != six[j]){
                possible = false;
                break;
            }
        }
        if(possible) {
            cout << "YES\n";
        } else {
            cout << "NO\n";
        }
    }
}