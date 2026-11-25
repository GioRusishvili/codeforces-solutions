#include <iostream>
#include <cmath>
#include <string>
#include <vector>
#include <map>
using namespace std;

int main() {
    int n;
    map<int, int> m;
    cin >> n;
    int most = 0;
    for(int i = 0; i < n; i++){
        int a;
        cin >> a;
        m[a]++;
        if(m[a] > most) most = m[a];
    }
    int result = n - most;
    cout << result;
}