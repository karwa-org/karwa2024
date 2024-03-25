#include "validation.h"

using namespace std;
#define int long long

signed main(int argc, char *argv[]) {
    // Set up the input and answer streams.
    std::ifstream in(argv[1]);
    std::ifstream ans(argv[2]); // Only for custom checker.
    OutputValidator v(argc, argv);
    map<int, multiset<int>> poss;

    /*************************************************************************************/
    /*                                  READ INPUT FILE                                  */
    /*************************************************************************************/
    int n; in >> n;
    vector<pair<int, int>> a(n);
    vector<int> def(n);
    for(int i = 0; i < n; i++) {
        in >> a[i].first;
        def[i] = a[i].first;
        a[i].second = i;
    }

    vector<int> b(n);
    for(auto& i : b) in >> i;

    sort(b.begin(), b.end(), greater<int>());
    sort(a.begin(), a.end(), [](pair<int, int> a, pair<int, int> b) {return a.first > b.first;});
    
    for(int i = 0; i < n; i++) {
        poss[def[a[i].second]].insert(a[i].first * b[i]);
        a[i].first *= b[i];
    }

     /*************************************************************************************/
    /*                                  READ ANS & student FILE                           */
    /*************************************************************************************/
    for(int i = 0; i < n; i++) {
        int tot = v.read_integer("answer", 1, 10e9);
        if(poss[def[i]].empty()) {
            v.WA("Invalid value empty in set searching for :", tot, " and ", i, " and ", def[i]);
        }
        if(poss[def[i]].find(tot) == poss[def[i]].end()) {

            v.WA("Invalid value not found got ", tot, " and ", i);
        }
        poss[def[i]].erase(poss[def[i]].find(tot));
        v.newline();
    }
    for(auto& i : poss) {
        if(!i.second.empty()) {
            v.WA("all set are not empty :", *i.second.begin());
        }
    }
}
