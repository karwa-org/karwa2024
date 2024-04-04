#include <iostream>
#include <iomanip>
#include <cmath>
#include <vector>
#include <algorithm>

using namespace std;
#define int long long

void solve() {
    int n, k; cin >> n >> k;
    vector<pair<string, int>> a(n);
    for(auto& i : a){
        cin >> i.first >> i.second;
    }

    sort(a.begin(), a.end(), [](pair<string, int> a, pair<string, int> b) {
        return a.second > b.second;
    });

    vector<string> ans;
    for(int i = 0; i < n; i++) {
        if(k >= a[i].second) {
            k -= a[i].second;
            ans.push_back(a[i].first);
        } else {
            break;
        }
    }

    if(k == 0) {
        cout << ans.size() << "\n";
        for(auto& i : ans) {
            cout << i << "\n";
        }
    } else {
        cout << -1 << "\n";
    }
}

signed main() {
    solve();
    return 0;
}