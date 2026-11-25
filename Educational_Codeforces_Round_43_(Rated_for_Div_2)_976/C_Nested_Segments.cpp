#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>
using namespace std;
int main() {
    int n;
    cin >> n;
    vector<tuple<int, int, int>> segs(n);
    for (int i = 0; i < n; i++) {
        int l, r;
        cin >> l >> r;
        segs[i] = make_tuple(l, r, i+1);
    }   
    sort(segs.begin(), segs.end(), [](const tuple<int,int,int>& a, const tuple<int,int,int>& b) {
        if (get<0>(a) != get<0>(b)) return get<0>(a) < get<0>(b);   // l ascending
        return get<1>(a) > get<1>(b);                                // tie: r descending
    });
    int max_r = 0;
    int max_index = 0;
    for (const auto& t : segs) {
        int curr_r = get<1>(t);
        int curr_index = get<2>(t);
        if (curr_r <= max_r) {
            cout << curr_index << " " << max_index << "\n";
            return 0;
        } else {
            max_r = curr_r;
            max_index = curr_index;
        }
    }
    cout << "-1 -1\n";
    return 0;
}