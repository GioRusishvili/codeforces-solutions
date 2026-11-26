#include <bits/stdc++.h>
using namespace std;
//void solve(){
    
//}
int main() {
   string s;
   if (!(cin >> s)) return 0;
   int upper_count = 0;
   int lower_count = 0;

   for (unsigned char c : s) {
      if (isupper(c)) {
         upper_count++;
      } else if (islower(c)) {
         lower_count++;
      }
   }

   for (char &c : s) {
      if (upper_count > lower_count) {
         c = static_cast<char>(toupper(static_cast<unsigned char>(c)));
      } else {
         c = static_cast<char>(tolower(static_cast<unsigned char>(c)));
      }
   }
   cout << s << '\n';
   return 0;
}