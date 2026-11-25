#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int main() {
    int n, d;
    cin >> n >> d;
    pair<int, int> p[n];
    for(int i = 0; i < n; i++){
        cin >> p[i].first >> p[i].second;
    }
    int size = sizeof(p) / sizeof(p[0]);
    sort(p, p + size);
    long long preSum[n];
    preSum[0] = p[0].second;
    for(int i = 1; i < n; i++){
        preSum[i] = p[i].second + preSum[i-1];
    }
    int p1 = 0;
    long long result = 0;
    for(int i = 0; i < n; i++){
        while(p[i].first - p[p1].first >= d) p1++;
        long long windowSum = (p1 == 0) ? preSum[i] : preSum[i] - preSum[p1 - 1];
        result = max(result, windowSum);
    }
    cout << result;
}