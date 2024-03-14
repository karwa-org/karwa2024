#include <iostream>
#include <iomanip>
#include <cmath>
#include <vector>
#include <queue>
#include <limits>

using namespace std;

const int INF = numeric_limits<int>::max()/2;

void dfs(int current, vector<vector<int>>& adj, vector<bool>& visited, vector<bool>& f, int depth, vector<int>& dist) {
	if(visited[current]){
		cout << "Impossible\n";
		exit(0);
	}
	
	visited[current] = true;
	
	if(current == 1){
		cout << depth -1 << endl;
		exit(0);
	}
	int maxdist = -1;
	int mindist = INF;
	int idx = -1;
	if(f[current]) {
		for(auto& k : adj[current]){
			if(dist[k] > maxdist){
				maxdist = dist[k];
				idx = k;
			}
		}
		if(idx == -1) return;
		dfs(idx, adj, visited, f, depth+1, dist);
	} else {
		bool direct = false;
		for(auto& k : adj[current]){
			if(dist[k] < mindist){
				mindist = dist[k];
				idx = k;
			}
			if(k == 1) {
				dfs(k, adj, visited, f, depth+1,dist);
				direct = true;
			}
		}
		if(idx == -1) return;
		if(!direct){
			dfs(idx, adj, visited, f, depth+1, dist);
		}
	}
}

void solve() {
	int n, m; cin >> n >> m;
	vector<bool> f(n);
	for(int i = 0; i < n; i++){
		int q; cin >> q;
		f[i] = (bool)(q);
	}
	
	vector<vector<int>> adj(n);
	vector<vector<int>> rev_adj(n);
	
	for(int i = 0; i < m; i++) {
		int u, v; cin >> u >> v;
		adj[u].push_back(v);
		rev_adj[v].push_back(u);
	}
	
	queue<int> q;
	q.push(1);
	vector<int> dist(n, INF);
	dist[1] = 0;
	
	//NOT SURE IF IT COULD BE HACKED
	vector<int> cnt(n, 0); // FAILSAFE we should pass at most once in a node during the dfs if more then it is a loop
		
	while(!q.empty()){
		int current = q.front(); q.pop();
		for(auto& k : rev_adj[current]){
			if(dist[k] == INF || dist[k] > dist[current] +1 || (f[k] && dist[k] < dist[current] +1 && dist[current] < 10000 && cnt[current] < 4)){
				dist[k] = dist[current]+1;
				cnt[k]++;
				q.push(k);
			}
		}
	}

	dist[1] = 0;
	vector<bool> visited(n, false);
	
	dfs(0, adj, visited, f, 0, dist);
	cout << "Impossible\n";
}

    
signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    solve();
    return 0;
 
}
