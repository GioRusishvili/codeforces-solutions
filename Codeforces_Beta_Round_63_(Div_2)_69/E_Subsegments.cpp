#include <iostream>
#include <cmath>
#include <map>
#include <set>
using namespace std;

int main() {
    int n, k;
    cin >> n;
    cin >> k;
    int a[n];
    for(int i = 0; i < n; i++){
        cin >> a[i];
    }
    map<int, int> freq;
    set<int> s;
    for(int i = 0; i < k; i++){
        freq[a[i]]++;
        if(freq[a[i]] == 1){
            s.insert(a[i]);
        } else if(freq[a[i]] == 2){
            s.erase(a[i]);
        }
    }
    if(s.empty()){
        cout << "Nothing" << endl;
    } else {
        cout << *s.rbegin() << endl;
    }
    for(int i = 0; i < n - k; i++){
        freq[a[i]]--;
        if(freq[a[i]] == 1){
            s.insert(a[i]);
        } else if(freq[a[i]] == 0){
            freq.erase(a[i]);
            s.erase(a[i]);
        }
        int end = i+k;
        freq[a[end]]++;
        if(freq[a[end]] == 1){
            s.insert(a[end]);
        } else if(freq[a[end]] >= 2){
            s.erase(a[end]);
        }
        if(s.empty()){
            cout << "Nothing" << endl;
        } else {
            cout << *s.rbegin() << endl;
        }
    }
}