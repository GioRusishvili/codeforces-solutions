#include <iostream>
using namespace std;

int main() {
    int n, k;
    cin >> n;
    cin >> k;
    int a[51];
    for(int i = 1; i <= n; i++){
        cin >> a[i];
    }
    int lowest = a[k];
    int index = 1;
    int result = 0;
    while(index <= n && a[index] >= lowest && a[index] != 0){
        result++;
        index++;
    }
    cout << result;
}