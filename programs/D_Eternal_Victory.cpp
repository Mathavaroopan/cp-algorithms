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
#define sum(arr) accumulate(arr.begin(), arr.end(), 0LL)
#define endl '\n'
using namespace std;

const int mod = 1e9 + 7;
int inf = 1e18;

int n;
vector<vector<pair<int, int>>> adj;
vector<vector<int>> dp;
int ans = 0;
void dfs(int node, int parent = -1){
    int temp = 0;
    for(auto v : adj[node]){
        if(v.first == parent) continue;
        dfs(v.first, node);
        temp = min(temp, -dp[v.first][0] - v.second + dp[v.first][1]);
        dp[node][0] += dp[v.first][0] + 2 * v.second;
    }
    dp[node][1] += dp[node][0] + temp;
}

void solve(){
    cin >> n;   
    dp.assign(n + 1, vector<int>(2, 0));
    adj.assign(n + 1, vector<pair<int, int>>());
    for(int i = 0; i < n - 1; i++){
        int u, v, w; cin >> u >> v >> w;
        adj[u].push_back({v, w});
        adj[v].push_back({u, w});
    } 
    dfs(1, -1);
    cout << dp[1][1] << endl;
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
 