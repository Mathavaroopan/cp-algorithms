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
#define sum(arr) accumulate(arr.begin(), arr.end(), 0LL)
#define endl '\n'
using namespace std;

const int mod = 1e9 + 7;
int inf = 1e18;
int n;
vector<vector<pair<int,int>>> adj;
vector<int> down, up, dp;
int tot = 0;
void dfs(int node, int parent){
    for(auto v : adj[node]){
        if(v.first == parent) continue;
        down[v.first] = (v.second == 0) + down[node];
        up[v.first] = (v.second == 1) + up[node];
        tot += (v.second == 1);
        dfs(v.first, node);
    }
}

void solve(){
    cin >> n;
    dp.assign(n + 1, 0);
    up.assign(n + 1, 0);
    down.assign(n + 1, 0);
    adj.resize(n + 1);
    for(int i = 0; i < n - 1; i++){
        int u, v; cin >> u >> v;
        adj[u].push_back({v, 0});
        adj[v].push_back({u, 1});
    }
    dfs(1, -1);
    for(int i = 1; i <= n; i++){
        dp[i] = tot - up[i] + down[i];
    }
    int ans = *min_element(dp.begin() + 1, dp.end());
    cout << ans << endl;
    for(int node = 1; node <= n; node++) if(dp[node] == ans) cout << node << " ";
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
 