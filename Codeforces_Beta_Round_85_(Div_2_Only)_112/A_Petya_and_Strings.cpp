#include <iostream>
#include <cmath>
#include <map>
#include <string>
#include <set>
using namespace std;

int main() {
    string first, second;
    cin >> first;
    cin >> second;
    
    for (char &c : first) {
        c = tolower(static_cast<unsigned char>(c)); 
    }
    for (char &c : second) {
        c = tolower(static_cast<unsigned char>(c)); 
    }
    if(first < second){
        cout << "-1";
    }else if(second < first){
        cout << "1";
    } else {
        cout << "0";
    }
}