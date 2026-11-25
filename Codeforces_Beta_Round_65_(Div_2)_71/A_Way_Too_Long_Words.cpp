#include <iostream>
#include <cmath>
#include <map>
#include <set>
using namespace std;

int main() {
    int n;
    cin >> n;
    string a[n];
    for(int i = 0; i < n; i++){
        cin >> a[i];
    }
    for(int i = 0; i < n; i++){
        string cur = a[i];
        if(cur.length() > 10){
            cout << cur[0] << cur.length() - 2 << cur[cur.length()-1] << endl;
        } else {
            cout << cur << endl;
        }
    }
}