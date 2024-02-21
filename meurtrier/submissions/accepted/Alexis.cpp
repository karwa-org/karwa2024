#include <iostream>
#include <iomanip>
#include <cmath>
#include <vector>
#include <unordered_set>
#include <algorithm>
#include <random>
#include <cassert>

using namespace std;

string query(string a, string b) {
    cout << "? " << a << " " << b << endl; // a à vu b ?
    string response; cin >> response;
    return response;
}

void solve() {
    int n; cin >> n;
    
    unordered_set<string> remaining_suspects;
    vector<string> suspects (n);

    for(int i = 0; i < n; i++) {
        string people; cin >> people;
        suspects[i] = people;
    }

    int current_supect = 0;
    for(int i = 0; i < n-1; i++) {
        string o = query(suspects[current_supect], suspects[i]);
        if (o == "NON") {
            current_supect = i;
        }
    }
    cout << "! " << suspects[current_supect] << endl;
    
}

int main() {
    solve();
    return 0;
}
