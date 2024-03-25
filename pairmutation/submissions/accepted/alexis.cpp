#include <iostream>
#include <iomanip>
#include <cmath>
#include <unordered_map>
#include <set>
#include <vector>

using namespace std;

int main() {
    int n; cin >> n;
    vector<int> a(n);
    vector<int> pos(n+1);

    for(auto& i : a) cin >> i;
    
    for(int i = 0; i < n; i++) {
        pos[a[i]] = i;
    }

    int ans = 0;
    for(int i = 0; i < n; i++) {
        if(a[i] != (i+1)) {
            int temp = a[i];
            swap(a[pos[i+1]], a[i]);
            swap(pos[i+1], pos[temp]);

            ans++;
        }
    }
    
    cout << (((ans%2) == 0) ? "Pair" : "Impair") << endl;
}