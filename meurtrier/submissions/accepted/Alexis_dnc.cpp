#include <iostream>
#include <iomanip>
#include <cmath>
#include <vector>
#include <unordered_set>
#include <algorithm>
#include <random>
#include <cassert>

using namespace std;

void query(string a, string b, vector<string>& to_remove) {
    cout << "? " << a << " " << b << endl; // a à vu b ?
    string response; cin >> response;
    if (response == "OUI") { // Oui alors on sait que c'est pas b le meurtrier
        to_remove.push_back(b);
    } else if (response == "NON") {
        to_remove.push_back(a);
    } else {
        assert(false); // should not happen.
    }
}

void solve() {
    int n; cin >> n;
    
    unordered_set<string> remaining_suspects;
    vector<string> suspects (n);

    for(int i = 0; i < n; i++) {
        string people; cin >> people;
        remaining_suspects.insert(people);
        suspects[i] = people;
    }

    while(true) {
        
        vector<string> v_suspects(remaining_suspects.begin(), remaining_suspects.end());

        int remaining_size = remaining_suspects.size();

        if(remaining_size == 2) {

            cout << "? " << v_suspects[1] << " " << v_suspects[0] << endl; // cneck if a has seen b

            string response; cin >> response;

            if (response == "OUI") { // Oui alors on sait que c'est pas b le meurtrier
                cout << "! " << v_suspects[1] << endl;
                return;
            } else if (response == "NON") {
                cout << "! " << v_suspects[0] << endl;
                return;
            }

        } else if ( remaining_size == 1) {
            cout << "! " << v_suspects[0] << endl;
            return;
        }

        int offset = remaining_size / 2;

        vector<string> to_remove; // do not remove while itterating through the multiset

        for(int i = 0; i < offset; i++) {
            string a = v_suspects[i];
            string b = v_suspects[i + offset];

            query(a, b, to_remove);

        }

        for (int i = 0; i < to_remove.size(); i++) {
            remaining_suspects.erase(to_remove[i]);
        }
    }
    
}

int main() {
    solve();
    return 0;
}
