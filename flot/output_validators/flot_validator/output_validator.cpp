#include "validation.h"
#include <queue>
#include <utility>
#include <functional>

using namespace std;

struct edge {
    int u;
    int v;
    int c;
};

int main(int argc, char *argv[]) {
    // Set up the input and answer streams.
    std::ifstream in(argv[1]);
    std::ifstream ans(argv[2]); // Only for custom checker.
    
    int n, m; in >> n >> m;

    vector<vector<edge>> adj(n);

    for(int i = 0; i < m; i++){
        int u, v; in >> u >> v;
        u--; v--;

        adj[u].push_back({u, v, 5});
    }

    int d; in >> d;
    vector<int> start(d);
    for(auto& i : start) {
        in >> i; i--;
    }

    int a; in >> a;
    vector<int> end(a);
    for(auto& i : end){ 
        in >> i; i--;
    }
    
    OutputValidator v(argc, argv);
    
    for(int i = 0; i < a; i++) {
        int ans_idx; ans >> ans_idx;
        int student_idx = v.read_integer("idx", -1, n);
        v.newline();

        if(ans_idx != student_idx) {
            v.WA("Got ", student_idx, " but wanted ", ans_idx);
        }
    }
}
