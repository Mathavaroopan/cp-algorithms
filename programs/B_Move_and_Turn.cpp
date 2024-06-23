/* Author: Mathavaroopan */
#include "bits/stdc++.h"
#define int long long
#define srt(arr) sort(arr.begin(), arr.end())
using namespace std;

set<pair<int, int>> s;
map<tuple<int, pair<int, int>, int>, int> mp;

int fun(int n, pair<int, int> p, int up) {
    if (n == 0) {
        if (!s.count(p)) {
            s.insert(p);
            return mp[{n, p, up}] = 1;
        }
        return mp[{n, p, up}] = 0;
    }
    if (mp.count({n, p, up})) return mp[{n, p, up}];
    int ns = 0, we = 0;
    if (up != 0) ns = fun(n - 1, {p.first, p.second + 1}, 0) + fun(n - 1, {p.first, p.second - 1}, 0);
    if (up != 1) we = fun(n - 1, {p.first + 1, p.second}, 1) + fun(n - 1, {p.first - 1, p.second}, 1);
    return mp[{n, p, up}] = ns + we;
}

void solve() {
    int n;
    cin >> n;
    
}
 
int32_t main()
{
 
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
 
    int T = 1;
    // cin >> T;
    while (T--) solve();
    return 0;
}
 