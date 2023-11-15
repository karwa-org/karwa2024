#include <iostream>
#include <iomanip>
#include <cmath>
#include <vector>
using namespace std;
#define int long long

const int max_n = 64;
const int max_k = (int)(10e5);

vector<string> dp [max_n+1][max_k+1];

void solve() {
    int n, k; cin >> n >> k;
    vector<pair<string, int>> a(n);

    for(auto& i : a){
        cin >> i.first >> i.second;
    }

    for(int i = 1; i <= n; i++) {
        for(int j = 0; j <= k; j++) {
            dp[i][j] = dp[i-1][j];
            if(j-a[i-1].second > 0 && i-1 > 0 && dp[i-1][j-a[i-1].second].size() != 0) {
                dp[i][j] = dp[i-1][j-a[i-1].second];
                dp[i][j].push_back(a[i-1].first);
            } else if(j-a[i-1].second == 0) {
                dp[i][j].push_back(a[i-1].first);
            } 
        }
    }

    vector<string> ans;
    for(int i = 1; i <= n; i++) {
        if(dp[i][k].size() != 0){
            cout << dp[i][k].size() << "\n";
            for(auto& i : dp[i][k]) cout << i << "\n";
            return;
        }
    }

    cout << -1 << "\n";
    
}

signed main() {
    solve();
    return 0;
}
