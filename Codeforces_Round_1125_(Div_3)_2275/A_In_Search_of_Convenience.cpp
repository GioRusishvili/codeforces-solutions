#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>
#include <cmath>
using namespace std;
int main() {
    int t;
    cin >> t;
    for(int i = 0; i < t; i++){
        int x, y, R;
        cin >> x >> y >> R;
        cout << x+R << " " << y << endl;
    }
}