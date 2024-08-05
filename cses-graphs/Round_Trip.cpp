/* Author: Mathavaroopan */
#include "bits/stdc++.h"
#define int long long
#define double long double
#define srt(arr) sort(arr.begin(), arr.end())
#define srtrev(arr) sort(arr.begin(), arr.end(), greater<int>())
#define reverse(arr) reverse(arr.begin(), arr.end())
#define all(arr) arr.begin(), arr.end()
#define input(arr) for(int& a : arr) cin >> a
#define print(arr) for(int i : arr) cout << i << " "
#define var(a) cout << #a << " = " << a << endl
#define min(arr) *min_element(arr.begin(), arr.end())
#define max(arr) *max_element(arr.begin(), arr.end())
#define sum(arr) accumulate(arr.begin(), arr.end(), 0)
#define endl '\n'
using namespace std;

const int mod = 1e9 + 7;
int inf = 1e18;

vector<int> vis;
int src = -1, dest = -1;

bool dfs(int node, vector<vector<int>>& g, int parent = inf) {
    for(int x : g[node]) {
        if(vis[x] == -1) {
            vis[x] = node;
            if(dfs(x, g, node)) return true;
        }else if(x != parent) {
            src = x, dest = node;
            return true;
        }
    }
    return false;
}

void solve() {
    int n, m; cin >> n >> m;
    vis.assign(n, -1);
    vector<vector<int>> g(n);
    for(int i = 0; i < m; i++){
        int u, v; cin >> u >> v; u--, v--;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    for(int i = 0; i < n; i++) {
        if(vis[i] == -1) {
            vis[i] = inf;
            if(dfs(i, g)){
                vector<int> ans = {src + 1};
                int cur = dest;
                while(cur != src) {
                    ans.push_back(cur + 1);
                    cur = vis[cur];
                }
                ans.push_back(src + 1);
                reverse(ans);
                cout << ans.size() << endl;
                print(ans);
                return;
            }
        }
    }
    cout << "IMPOSSIBLE" << endl;
}

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int T = 1;
    while (T--) solve();
    return 0;
}
