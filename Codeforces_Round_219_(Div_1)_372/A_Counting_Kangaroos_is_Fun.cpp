#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>
using namespace std;
int main() {
    int n;
    cin >> n;
    vector<int> v(n);
    for (int i = 0; i < n; i++) {
        cin >> v[i];
    }
    sort(v.begin(), v.end());
    int left = 0;
    int right = n/2;
    int count = 0;
    while(left < n / 2 && right < n){
        if(v[right] >= v[left]*2){
            count++;
            left++;
        }
        right++;
    }
    cout << n - count;
}