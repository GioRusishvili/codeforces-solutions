#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
using namespace std;

int main() {
    int n, m;
    cin >> n >> m;
    set<int> alive;
    for(int i = 1; i <= n; i++) alive.insert(i);
    int ans[n] = {};
    set<int>::iterator it = alive.begin();
    for(int i = 0; i < m; i++){
        int l, r, x;
        cin >> l >> r >> x;
        it = alive.lower_bound(l);
        while(it != alive.end() && *it <= r){
            if(*it != x) {
                ans[*it-1] = x;
                it = alive.erase(it);
            } else it++;
        }
    }
    for(int i = 0; i < n-1; i++){
        cout << ans[i] << " ";
    }
    cout << ans[n-1];
}