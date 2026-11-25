#include <iostream>
#include <unordered_map>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    unordered_map<string, int> m;
    int n;
    cin >> n;
    for(int i = 0; i < n; i++){
        string s;
        cin >> s;
        if (auto it = m.find(s); it != m.end()) {
            cout << s << ++it->second << endl;
        } else {
            m[s] = 0;
            cout << "OK" << endl;
        }
    }
}