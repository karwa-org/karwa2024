#include <iostream>
#include <iomanip>
#include <cmath>
#include <vector>
#include <string>

using namespace std;
#define int long long

vector<string> recurse(vector<pair<string, int>>& a, int offset, int sum) {
    
    if (sum == 0) {
        return vector<string>(1, a[offset+1].first);
    }
    
    if (sum < 0 || offset < 0) {
        return vector<string>();
    }

    

    vector<string> v = recurse(a, offset - 1, sum);
    
    if(v.size() != 0) {
        return v;
    }

    v = recurse(a, offset - 1, sum - a[offset].second);
    if (v.size() != 0) {
        v.push_back(a[offset].first);
        return v;
    }

    return v;
}


void solve() {
    int n, k; cin >> n >> k;
    vector<pair<string, int>> a(n);

    if (k == 0) {
        cout << 0 << endl;
        return;
    }

    for(auto& i : a) cin >> i.first >> i.second;

    vector<string> ans = recurse(a, n-1, k);

    if (ans.size() <= 0) {
        cout << -1 << endl;
    } else {
        cout << ans.size()-1 << endl;
        for(int i = 1; i < ans.size(); i++) {
            cout << ans[i] << endl;
        }
    }
}

signed main() {
    solve();
    return 0;
}