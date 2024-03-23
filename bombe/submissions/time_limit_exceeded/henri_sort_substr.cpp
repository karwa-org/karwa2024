#include <bits/stdc++.h>
 
#define int long long
#define P(x) {if (debug) cout << x << endl;}
#define H(x) P(#x << ": " << (x))
#define FR(i,a,b) for (int i=(a); i<(b); i++)
#define F(i,n) FR(i,0,n)
#define D(i,n) for (int i=(n); i-->0;)
#define S(s) (int)(s).size()
#define ALL(v) v.begin(), v.end()
#define MI(a,v) a = min(a,v)
#define MA(a,v) a = max(a,v)
#define V vector
#define pb push_back
#define mt make_tuple
 
using namespace std;
 
template<class T> ostream& operator<<(ostream& os, V<T> v) {
    F(i,S(v)) os<<(i?" ":"")<<v[i]; 
    return os;
}
 
const bool debug = 1;

int n, m;
V<string> tab;

map <string, vector<int> > hashed_strings;

bool compare_strings(string s0, string s1) {
    F(i, m) {
        string s = s0.substr(i, m-i) + s0.substr(0, i);
        if(s == s1) return true;
    }
    return false;
}

map <string, int> strings2ids;

signed main () {
    cin >> n >> m;
    pair <int, int> ans = make_pair(100000, 100000);

    F(i, n) {
        string s; cin >> s; tab.pb(s);
    }

    F(i, n) {
        string s = tab[i];
        sort(ALL(s));
        if(hashed_strings.count(s) == 0) hashed_strings[s] = V<int>();
        hashed_strings[s].push_back(i);
    }

    for(auto i: hashed_strings) {
        V<int> v = i.second;
        F(i, S(v)) {
            FR(j, i+1, S(v)) {
                if(compare_strings(tab[v[i]], tab[v[j]])) {
                    if(ans.first == 100000 || (ans.first > v[i]+1 || (ans.first == v[i]+1 && ans.second > v[j]+1))) {
                        ans = make_pair(v[i]+1, v[j]+1);
                    }
                }
            }
        }
    } 
    if(ans.first == 100000) {
        cout << "BOOM!" << endl;
    }
    else {
        cout << ans.first << " " << ans.second << endl;
    }
}
