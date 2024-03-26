#include <stdio.h>
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

#define int long long

void solve () {
    int n; cin >> n;
    vector<pair<int, int>> a(n);
    vector<int> b(n);
    
    for(int i = 0; i < n; i++) {
        cin >> a[i].first;
        a[i].second = i;
    }

    for(auto& i : b) cin >> i;

    sort(a.begin(), a.end(), [](pair<int, int> a, pair<int, int> b) {return a.first >= b.first;});
    
    sort(b.begin(), b.end(), greater<int>());

    for(int i = 0; i < n; i++) {
        a[i].first *= b[i];
    }

    for(auto& i : a) cout << i.first << "\n";
}

signed main(void) {
    solve();
    return 0;
}