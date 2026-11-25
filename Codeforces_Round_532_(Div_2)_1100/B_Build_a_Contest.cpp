#include <iostream>
#include <cmath>
#include <string>
#include <vector>
#include <map>
using namespace std;

int main() {
    int n, m;
    cin >> n >> m;
    map<int, int> m1;
    map<int, int> m2;
    string result = "";
    for(int i = 0; i < m; i++){
        int a;
        cin >> a;
        m1[a]++;
        m2[m1[a]]++;
        if(m2[m1[a]] == n) result += "1";
        else result += "0";
    }
    cout << result;
}