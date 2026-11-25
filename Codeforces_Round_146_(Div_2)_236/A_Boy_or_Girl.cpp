#include <iostream>
#include <cmath>
#include <map>
#include <string>
#include <set>
using namespace std;

int main() {
    string name;
    cin >> name;
    set<char> s;
    for(int i = 0; i < name.length(); i++){
        s.insert(name[i]);
    }
    int count = s.size();
    if(count % 2 != 0){
        cout << "IGNORE HIM!";
    } else {
        cout << "CHAT WITH HER!";
    }
}