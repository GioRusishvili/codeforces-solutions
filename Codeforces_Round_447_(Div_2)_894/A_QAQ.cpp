#include <bits/stdc++.h>
using namespace std;
int main() {
    string s;
    cin >> s;
    int q = 0;
    int qa = 0;
    int qaq = 0;
    for (char c : s) {
        if (c == 'Q') { qaq += qa; q++; }
        else if (c == 'A') { qa += q; }
    }
    cout << qaq;
    return 0;
}