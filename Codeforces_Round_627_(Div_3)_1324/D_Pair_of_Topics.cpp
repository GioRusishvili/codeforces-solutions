#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    int n;
    cin >> n;
    vector<int> a(n);
    vector<int> b(n);
    vector<int>d(n);
    for(int i = 0; i < n; i++){
        cin >> a[i];
    }
    for(int i = 0; i < n; i++){
        cin >> b[i];
        d[i] = a[i] - b[i];
    }
    int left = 0, right = n-1;
    long long count = 0;
    sort(d.begin(), d.end());
    while(left < right){
        if(d[left] + d[right] > 0){
            count += right - left;
            right--;
        } else left++;
    }
    cout << count;
}