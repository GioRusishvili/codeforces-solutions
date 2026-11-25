#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>
using namespace std;
int main() {
    int n;
    cin >> n;
    unordered_map<int, long long> freq;
    unordered_map<int, long long> dp;
    int largest = 0;
    for (int i = 0; i < n; i++) {
        int a;
        cin >> a;
        if(largest < a) largest = a;
        freq[a]++;
    }
    dp[0] = 0;
    dp[1] = freq[1] * 1;
    for(int i = 2; i <= largest; i++){
        dp[i] = max(dp[i-1], dp[i-2] + i*freq[i]);
    }
    cout << dp[largest];
}