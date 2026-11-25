#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>
using namespace std;
int main() {
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    vector<int> score(n + 1, 0);
    int max1 = 0;
    int max2 = 0;
    for (int i = 0; i < n; i++) {
        if (a[i] > max1) {
            score[a[i]]--;
            max2 = max1;
            max1 = a[i];
        } else if (a[i] > max2) {
            score[max1]++;
            max2 = a[i];
        }
    }
    int best_val = 1;
    for (int val = 2; val <= n; val++) {
        if (score[val] > score[best_val]) {
            best_val = val;
        }
    }

    cout << best_val << "\n";
}