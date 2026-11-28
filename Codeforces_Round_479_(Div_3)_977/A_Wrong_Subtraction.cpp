#include <bits/stdc++.h>
using namespace std;
//void solve(){
    
//}
int main() {
   long long n;
    int k;
    if (!(cin >> n >> k)) return 0;

    for (int i = 0; i < k; ++i) {
        if (n % 10 != 0) {
            n -= 1;
        } else {
            n /= 10;
        }
    }
    
    cout << n << '\n';
    return 0;
}