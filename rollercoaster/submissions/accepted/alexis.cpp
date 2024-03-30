#include <iostream>
#include <iomanip>
#include <cmath>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;


void solve() {
    int n, a; cin >> n >> a;

    vector<string> ans;

    for(int i = 0; i < n; i++) {
        string s; cin >> s;
        int m; cin >> m;
        int prev = -1;
        int maxii = -1e9;
        for(int j = 0; j < m; j++) {
            int x; cin >> x;
            if(prev == -1) {    
                prev = x;
                continue;
            }
            maxii = max(prev - x, maxii);
            prev = x;
        }
        if(maxii <= a) {
            ans.push_back(s);
        }
    }
    cout << ans.size() << endl;
    for(auto x : ans) {
        cout << x << endl;
    }
}

int main() {
    solve();
    return 0;
}
