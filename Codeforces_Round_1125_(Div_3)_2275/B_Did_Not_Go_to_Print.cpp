#include <iostream>
#include <vector>
#include <string>
using namespace std;
void helper() {
    int n;
    cin >> n;
    string s;
    cin >> s;
    vector<int> st;
    vector<bool> printed(n + 1, false); 
    for(int i = 1; i <= n; i++) {
        char type = s[i - 1];
        if (type == '1') {
            st.push_back(i);
        } else if(type == '2') {
            if (!st.empty()) {
                int top = st.back();
                st.pop_back();
                printed[top] = true;
            } else {
                printed[i] = true;
            }
        } else if(type == '3') {
            printed[i] = true;
        }
    }
    vector<int> unprinted;
    for(int i = 1; i <= n; i++) {
        if (!printed[i]) {
            unprinted.push_back(i);
        }
    }
    cout << unprinted.size() << "\n";
    for(int i = 0; i < unprinted.size(); i++) {
        cout << unprinted[i] << (i + 1 == unprinted.size() ? "" : " ");
    }
    cout << "\n";
}
int main() {
    int t;
    cin >> t;
    for(int i = 0; i < t; i++){
        helper();
    }
    return 0;
}