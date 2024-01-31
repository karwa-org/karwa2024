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


int dijkstra(vector<vector<edge>>& rev_adj, int start, vector<int>& possible) {
    auto cmp = [](pair<int, int>& a, pair<int, int>& b ) {
        return a.second > b.second;
    };

    priority_queue<pair<int, int>, vector<pair<int, int>>, decltype(cmp)> pq(cmp);
    
    vector<int> dist (rev_adj.size(), INF);

    dist[start] = 0; 
    pq.push(make_pair(start, 0));
    
    while(! pq.empty()) {
        
        pair<int, int> current = pq.top(); pq.pop();
        for(edge& e : rev_adj[current.first]) {
            if(dist[e.v] > current.second + e.c) {
                dist[e.v] = current.second + e.c;
                pq.push(make_pair(e.v, dist[e.v]));
            }
        }
    }
    
    int min_idx = (int)10e9;
    int min_dist = (int)10e9;

    for(int i = 0; i < possible.size(); i++) {
        if(dist[possible[i]] <= min_dist) {            
            if(dist[possible[i]] < min_dist) min_idx = possible[i];
            min_dist = dist[possible[i]];
            if(min_idx > possible[i]) {
                min_idx = possible[i];
            }
        }
    }

    if(min_idx == (int)10e9) {
        return -1;
    }

    return min_idx+1;
}


void solve() {
    int n, m; cin >> n >> m;

    vector<vector<edge>> adj(n);
    vector<vector<edge>> rev_adj(n);

    for(int i = 0; i < m; i++){
        int u, v; cin >> u >> v;
        u--; v--;

        adj[u].push_back({u, v, 5});
        rev_adj[v].push_back({v, u, 5});
        
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

    for (int i = 0; i < a; i++) {
        cout << dijkstra(rev_adj, end[i], start) << endl;
    }
    
}

signed main() {
    solve();
    return 0;
}
