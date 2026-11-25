#include <iostream>
#include <cmath>
#include <string>
#include <vector>

using namespace std;

int main() {
    string s;
    cin >> s;
    vector<char> v;
    for(int i = 0; i < s.length(); i++){
        s[i] = tolower(s[i]);
    }
    for(char c : s){
        if(string("aeiouyAEIOUY").find(c) == string::npos){
            v.push_back(c);
        }
    }
    string res = "";
    for(char c : v){
        res += ".";
        res += c;
    }
    cout << res;
}