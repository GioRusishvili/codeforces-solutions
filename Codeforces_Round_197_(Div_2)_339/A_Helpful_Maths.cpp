#include <iostream>
#include <cmath>
#include <string>

using namespace std;

int main() {
    string s;
    cin >> s;
    int count1 = 0, count2 = 0, count3 = 0;
    for(int i = 0; i < s.length(); i += 2){
        if (s[i] == '1') count1++;
        else if (s[i] == '2') count2++;
        else if (s[i] == '3') count3++;
    }
    string res = "";
    while (count1--) res += "1+";
    while (count2--) res += "2+";
    while (count3--) res += "3+";
    res.pop_back();
    cout << res;
}