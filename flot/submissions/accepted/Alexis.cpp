#include <iostream>
#include <iomanip>
#include <cmath>
#include <vector>
#include <algorithm>
#include <queue>
#include <unordered_map>

using namespace std;

#define int long long

struct edge {
    int u;
    int v;
    int c;
};
const int INF = (int)10e18;

void solve() {
    int n, m; cin >> n >> m;
    vector<vector<edge>> adj(n);

    for(int i = 0; i < m; i++){
        int u, v; cin >> u >> v;
        u--; v--;

        adj[u].push_back({u, v, 5});
    }

    int d; cin >> d;
    vector<int> start(d);
    for(auto& i : start) {
        cin >> i;
        i--;
    }

    int a; cin >> a;
    vector<int> end(a);
    for(auto& i : end){ 
        cin >> i;
        i--;
    }
    
    queue<int> q;
    vector<int> dist (n, INF);

    unordered_map<int, int> min_start;
    unordered_map<int, bool> in_q;

    for(int i = 0; i < start.size(); i++) {
        dist[start[i]] = 0; 
        
        min_start[start[i]] = start[i];
        in_q[start[i]] = true;
        q.push(start[i]);
    }
    
    while(! q.empty()) {
        
        int current = q.front(); q.pop();
        in_q[current] = false;

        for(edge& e : adj[current]) {
            if(dist[e.v] == INF || dist[e.v] == dist[e.u] + e.c) {
                
                dist[e.v] = dist[e.u] + e.c;

                if(in_q[e.v] == false) {
                    q.push(e.v);
                    in_q[e.v] = true;
                }
                
                if(min_start.count(e.v) == 0) {
                    min_start[e.v] = min_start[e.u];
                } else {
                    min_start[e.v] = min(min_start[e.v], min_start[e.u]);
                }
            }
        }
    }

    for(int i = 0; i < end.size(); i++) {
        if(min_start.count(end[i]) == 0){
            cout << -1 << endl;
        }else {
            cout << min_start[end[i]]+1 << endl;
        }
    }
    
}

signed main() {
    solve();
    return 0;
}
