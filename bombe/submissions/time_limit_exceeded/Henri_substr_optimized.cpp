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

unordered_map <string, int> string2line;
pair <int, int> ans;
signed main () {
    cin >> n >> m;
    ans = make_pair(100000, 100000);
    F(i, n) {
        string s; cin >> s; tab.pb(s);
    }

    F(i, n) {
        F(j, m) {
            string s= tab[i].substr(j, m-j) + tab[i].substr(0, j);
            if(string2line.count(s) == 0) {
                string2line[s] = i;
            }
            else if(string2line[s] != i) {
                if(ans.first == 100000 || (ans.first > string2line[s]+1 || (ans.first == string2line[s]+1 && ans.second > i+1))) {
                    ans = make_pair(string2line[s]+1, i+1);
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
