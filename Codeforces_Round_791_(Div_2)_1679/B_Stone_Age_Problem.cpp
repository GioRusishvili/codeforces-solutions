#include <iostream>
#include <vector>
using namespace std;
int main() {
    int n, q;
    cin >> n >> q;
    vector<long long> personalValue(n + 1, 0);
    vector<long long> personalTime(n + 1, 0);
    long long currentSum = 0;
    for (int i = 1; i <= n; i++) {
        cin >> personalValue[i];
        currentSum += personalValue[i];
    }
    long long globalValue = 0;
    long long globalTime = -1;
    for (long long timeStamp = 1; timeStamp <= q; timeStamp++) {
        int queryType;
        cin >> queryType;
        if (queryType == 1) {
            int index;
            long long newValue;
            cin >> index >> newValue;
            long long oldValue = (personalTime[index] > globalTime) ? personalValue[index] : globalValue;
            currentSum -= oldValue;
            currentSum += newValue;

            personalValue[index] = newValue;
            personalTime[index] = timeStamp;
        }
        else if (queryType == 2) {
            long long newValue;
            cin >> newValue;

            globalValue = newValue;
            globalTime = timeStamp;
            currentSum = (long long)n * newValue;
        }
        cout << currentSum << "\n";
    }
    return 0;
}