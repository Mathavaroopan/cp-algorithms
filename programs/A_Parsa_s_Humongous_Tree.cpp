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
#define sum(arr) accumulate(arr.begin(), arr.end(), 0)
#define endl '\n'
using namespace std;

const int mod = 1e9 + 7;
int inf = 1e18;
int n;
vector<pair<int, int>> range;
vector<vector<int>> adj;
vector<vector<int>> dp;

void dfs(int node, int parent, int s){
    if(node != 1 && adj[node].size() == 1){
        dp[node][s] = dp[node][!s] = 0;
        return;
    }
    if(dp[node][s] != -1) return;
    for(int v : adj[node]){
        if(v == parent) continue;
        dfs(v, node, !s);
        dfs(v, node, s);
    }

    int ans = 0;
    for(int v : adj[node]){
        if(v == parent) continue;
        ans += max(abs((s ? range[node].first : range[node].second) - (s ? range[v].second : range[v].first)) + dp[v][!s],
                            abs((s ? range[node].first : range[node].second) - (s ? range[v].first : range[v].second)) + dp[v][s]);
    }
    dp[node][s] = ans;
}

void solve(){
    cin >> n;
    dp.assign(n + 1, vector<int>(2, -1));
    range.assign(n + 1, {0, 0});
    adj.assign(n + 1, vector<int>());
    for(int i = 1; i <= n; i++) cin >> range[i].first >> range[i].second;
    for(int i = 0; i < n - 1; i++){
        int u, v; cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    dfs(1, -1, 1);
    dfs(1, -1, 0);
    cout << max(dp[1][1], dp[1][0]) << endl;
}
 
int32_t main()
{
 
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
 
    int T = 1;
    cin >> T;
    while (T--) solve();
    return 0;
}
 