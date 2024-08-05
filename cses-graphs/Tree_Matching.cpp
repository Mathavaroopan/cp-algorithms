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
#define sum(arr) accumulate(arr.begin(), arr.end(), 0)
#define endl '\n'
using namespace std;

const int mod = 1e9 + 7;
int inf = 1e18;

vector<vector<int>> adj;
vector<vector<int>> dp;
void dfs(int node, int parent = -1){
    if(node != 1 && adj[node].size() == 1) return;
    int mx = -inf;
    dp[node][1] = 1;
    for(int v : adj[node]){
        if(v == parent) continue;
        dfs(v, node);
        dp[node][1] += dp[v][1];
        dp[node][0] += max(dp[v][0], dp[v][1]);
        mx = max(dp[v][0] - dp[v][1], mx);
    }
    dp[node][1] += mx;
}   

void solve(){
    int n;
    cin >> n;
    adj.assign(n + 1, vector<int>());
    dp.assign(n + 1, vector<int>(2, 0));
    for(int i = 0; i < n - 1; i++){
        int u, v; cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    dfs(1);
    cout << max(dp[1][0], dp[1][1]) << endl;
}
 
int32_t main()
{
 
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
 
    int T = 1;
    while (T--) solve();
    return 0;
}
 