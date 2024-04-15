#include <iostream>
#include <iomanip>
#include <cmath>
#include <vector>
using namespace std;
#define int long long

void solve() {
    const int max_n = 64;
    const int max_k = (int)3*(pow(10,5));
    int dp [max_n+1][max_k+1];

    int n, k; cin >> n >> k;
    vector<pair<string, int>> a(n);

    for(auto& i : a){
        cin >> i.first >> i.second;
    }

    // Worst time complexity is O(n * k) if we use the masking technique otherwise it is worse °_°

    for(int i = 1; i <= n; i++) {
        for(int j = 0; j <= k; j++) {
            dp[i][j] = dp[i-1][j];
            if(j-a[i-1].second > 0 && i-1 > 0 && dp[i-1][j-a[i-1].second] != 0) {
                dp[i][j] = (dp[i-1][j-a[i-1].second] | ((1LL) << i));
            } else if(j-a[i-1].second == 0) {
                dp[i][j] = (1LL << i);
            } 
        }
    }

    vector<string> ans;
    for(int i = 1; i <= n; i++) {
        if(dp[i][k] != 0){
            int mask = dp[i][k];
            for(int i = 1; i <= 64; i++) {
                if(((mask >> i) & 1) == 1) {
                    ans.push_back(a[i-1].first);
                }
            }
            break;
        }
    }

    if(ans.size() <= 0) {
        cout << -1 << "\n";
    } else {
        cout << ans.size() << "\n";
        for (auto& i : ans) {
            cout << i << "\n";
        }
    }
}

signed main() {
    solve();
    return 0;
}
