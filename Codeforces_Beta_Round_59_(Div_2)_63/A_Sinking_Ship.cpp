#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>
using namespace std;
int main() {
    int n;
    cin >> n;
    string captain;
    vector<string> second;
    vector<string> third;
    for (int i = 0; i < n; i++){
        string name, status;
        cin >> name >> status;
        if(status == "rat") cout << name << endl;
        else if(status == "woman" || status == "child") second.push_back(name);
        else if(status == "man") third.push_back(name);
        else captain = name;
    }
    for(string name : second) cout << name << endl;
    for(string name : third) cout << name << endl;
    cout << captain;
}