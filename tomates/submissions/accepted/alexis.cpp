#include <stdio.h>
#include <iostream>
#include <algorithm>
#include <math.h>

using namespace std;

int main() {
    long long v, t, p, l; cin >> v >> t >> p >> l;

    cout << max(v - ((t*p) - l), (long long)0) << endl;
}