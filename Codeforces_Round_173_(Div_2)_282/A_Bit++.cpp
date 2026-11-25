#include <iostream>
#include <cmath>
#include <map>
#include <set>
using namespace std;

int main() {
    int n;
    cin >> n;
    int res = 0;
    for(int i = 0; i < n; i++){
        string op;
        cin >> op;
        if(op[1] == '-') res--;
        else res++;
    }
    cout << res;
}