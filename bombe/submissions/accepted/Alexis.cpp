#include <iostream>
#include <iomanip>
#include <cmath>
#include <unordered_map>
#include <set>
#include <vector>

#define int long long

using namespace std;


//TODO: CHECK IF BAD CONSTANT TO BE FAIR DURING THE CONTEST
int MOD = (1LL << 59);
int A = 911382323;

int safeMod(int a, int m) {
    return (a % m + m) % m;
    }

void solve() {

    int n, m; cin >> n >> m;
    vector<vector<char>> a(n, vector<char>(m));
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            cin >> a[i][j];
        }
    }

    vector<int> pre(m);

    pre[0] = 1;
    for(int i = 1; i < m; i++) {
        pre[i] = safeMod((pre[i-1] * A), MOD);
    }
    vector<int> hs(n);
    unordered_map<int, set<int>> cnt;

    for(int i = 0; i < n; i++) {
        int hash = 0;

        for(int j = 0; j < m; j++) {
            hash += a[i][j] * pre[j];
            hash = safeMod(hash, MOD);
        }
        hs[i] = hash;
        cnt[hs[i]].insert(i+1);
    }

    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            hs[i] -= safeMod((a[i][m-j-1] * pre[m-1]), MOD);
            hs[i] = safeMod(hs[i],MOD);
            hs[i] *= A;
            hs[i] = safeMod(hs[i] ,MOD);
            hs[i] += a[i][m-j-1];
            hs[i] = safeMod(hs[i], MOD);

            cnt[hs[i]].insert(i+1);
        }
    }

    pair<int, int> mini = make_pair(10e9, 10e9);

    for(auto& k : cnt) {
        if(k.second.size() > 1) {
            pair<int, int> prop = make_pair(*k.second.begin(), *next(k.second.begin()));
            if(prop < mini) {
                mini = prop;
            }
        }
    }

    if(mini.first == 10e9 && mini.second == 10e9) {
        cout << "BOOM!\n";
    } else {
        cout << mini.first << " " << mini.second << endl;
    }
}

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    solve();

    return 0;
}
