#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    long long n, q;
    cin >> n >> q;
    vector<int> color(51,1e9);
    for(int i = 0; i < n; i++){
        int x; cin >> x;
        color[x] = min(color[x] , i + 1);
    }
    for(int i = 0; i < q; i++){
        int query; cin >> query;
        int temp = color[query];
        cout << temp << " ";
        color[query] = 1;
        for(int j = 1; j < 51; j++){
            if(j == query) continue;
            if(color[j] < temp){
                color[j] ++;
            }
        }
    }
    cout << endl ;
    return 0;
}