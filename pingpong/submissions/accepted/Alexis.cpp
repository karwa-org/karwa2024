#include <iostream>
#include <iomanip>
#include <cmath>
#include <vector>

using namespace std;

void solve() {
    int n; cin >> n;
    vector<int> a(n);
    vector<bool> in(1e6+1);

    int sum = 0;

    for(int i = 0; i < n; i++) {
        int t; cin >> t;
        in[sum+t] = true; 
        sum += t;
    }

    int best = 0;
    int step = 0;
    for(int i = 2; i < sum; i++) {
        int cnt = 0;
        for(int j = i; j <= sum; j+=i ) {
            if(in[j]) {
                cnt++;
            }
        }
        if (cnt > best) {
            best = cnt;
            step = i;
        }
    }

    cout << step << " " << best << endl;
}

int main () {
    solve();
    return 0;
}