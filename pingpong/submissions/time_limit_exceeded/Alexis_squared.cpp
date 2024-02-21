#include <iostream>
#include <iomanip>
#include <cmath>
#include <vector>

using namespace std;

void solve() {
    int n; cin >> n;
    vector<int> a(n);

    int sum = 0; // for later to be sure that even with this "little" optimisation it will fail
    for(auto& i : a ) {
        int t; cin >> t;
        i = sum + t;
        sum += t;
    }

    int best = 0;
    int step = 0;

    //Here is the part that MUST FAIL !
    for(int i = 2; i <= sum; i++) {
        int got = 0;
        for(auto& k : a) {
            if ((k%i) == 0) {
                got++;
            }
        }
        
        if(got > best) {
            best = got;
            step = i;
        }
    }
    cout << step << " " << best << endl;
}

int main () {
    solve();
    return 0;
}