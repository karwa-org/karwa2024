#include <iostream>
#include <iomanip>
#include <cmath>
#include <vector>
#include <algorithm>    

using namespace std;

int dp[500000][2]; // dp[i][t][weaponusedbefore]
// maximiser le nombre de guarde <=> maximiser le temps
// On a donc du O(n)

void solve() {
    int n, t; cin >> n >> t;
    vector<int> p(n);
    vector<int> c(n);
    vector<int> e(n);

    for(int i = 0; i < n; i++) {
        cin >> p[i] >> c[i] >> e[i];
    }

    for(int i = 0; i < n; i++) {
        for(int j = 0; j < 2; j++) {
            dp[i][j] = -1e9;
        }
    }

    dp[0][1] = max(t - p[0], t - e[0]); //on utilise le pistolet donc 
    dp[0][0] = max(t - c[0], t - e[0]); //on utilise le couteau donc

    for(int i = 1; i < n; i++) {
        dp[i][1] = max(max(dp[i-1][0] - p[i], dp[i-1][1] - e[i]), dp[i-1][0] - e[i]);
        dp[i][0] = max(max(dp[i-1][1] - c[i], dp[i-1][0] - e[i]), dp[i-1][1] - e[i]);
    }

    int ans = 0;
    int maxii = -1e9;
    for(int i = 0; i < n; i++) {
        if(dp[i][0] >= 0) {
            ans = i;
            maxii = dp[i][0];
        }
        if(dp[i][1] >= 0) {
            if(ans == i) {
                 maxii = max(maxii, dp[i][1]);
            } else {
                maxii = dp[i][1];
            }
            ans = i;
           
        }
    }

    cout << ans+1 << " " << t-maxii << endl;

}

int main() {
    solve();
    return 0;
}
