#include <iostream>
#include <vector>
using namespace std;
int OFFSET = 30005;
int freq[60015]; 
void helper() {
    int n;
    cin >> n;
    vector<int> a(n);
    for(int i = 0; i < n; i++){
        cin >> a[i];
    }
    int m = n - 4;
    vector<int> points(m);
    long long answer = 0;
    for(int i = 0; i < m; i++){
        points[i] = a[i] + a[i+2] - a[i+4];
        answer += freq[points[i] + OFFSET];
        freq[points[i] + OFFSET]++;
    }
    for(int i = 0; i + 2 < m; i++){
        if (points[i] == points[i+2]) answer--;
    }
    for(int i = 0; i + 4 < m; i++){
        if (points[i] == points[i+4]) answer--;
    }
    for(int i = 0; i < m; i++){
        freq[points[i] + OFFSET] = 0;
    }
    cout << answer << "\n";
}
int main() {
    int t;
    cin >> t;
    for(int i = 0; i < t; i++){
        helper();
    }
    return 0;
}