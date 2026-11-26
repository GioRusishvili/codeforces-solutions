#include <bits/stdc++.h>
using namespace std;
//void solve(){
    
//}
int main() {
   int k, n, w;
   cin >> k >> n >> w;
   int needs = k * (w*(w+1)/2);
   needs = needs - n;
   if(needs < 0) needs = 0;
   cout << needs;
}