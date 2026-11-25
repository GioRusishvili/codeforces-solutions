#include <iostream>
using namespace std;

int main() {
    int a[3001] = {};
    int n;
    cin >> n;
    for(int i = 2; i <= n-1; i++){
        if(a[i] != 0) continue;
        for(int j = i+1; j <= n; j++){
            if(j % i == 0) a[j]++;
        }
    }
    int result = 0;
    for(int i = 1; i <= n; i++){
        if(a[i] == 2) result++;
    }
    cout << result;
}