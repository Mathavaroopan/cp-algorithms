#include "bits/stdc++.h"
#define int long long

using namespace std;

const int mod = 998244353;
int c0 = 0, c1 = 0;

bool dfs(int node, vector<vector<int>>& adj, vector<int>& vis, vector<int>& color){
    vis[node] = 1;
    for(int x : adj[node]){
        if(color[x] == color[node]) return false;
        if(!vis[x]){
            color[x] = !color[node];
            if(color[x] == 0) c0++;
            else c1++;
            if(!dfs(x, adj, vis, color)) return false;
        }
    }
    return true;
}

void solve(){
    int n, m;
    cin >> n >> m;
    vector<vector<int>> adj(n);
    vector<int> vis(n, 0), color(n, -1);
    for(int i = 0; i < m; i++){
        int u, v;
        cin >> u >> v;
        u--, v--;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    vector<int> powers(n + 1, 1);

    for(int i = 1; i < n + 1; i++){
        powers[i] = (2 * powers[i - 1]) % mod;
    }

    int ans = 1;
    for(int i = 0; i < n; i++){
        if(!vis[i]){
            color[i] = 1;
            c0 = 0, c1 = 1;
            if(!dfs(i, adj, vis, color)){
                cout << 0 << endl;
                return;
            }
            ans = (ans * ((powers[c0] + powers[c1]) % mod)) % mod;
            c0 = 0, c1 = 0;
        }
    }
    cout << ans << endl;
}

int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int T = 1;
    cin >> T;
    while (T--)
    {
        solve();
    }
    return 0;
}
