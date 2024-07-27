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
int n;
vector<vector<pair<int, int>>> adj;
vector<int> fuel;
vector<vector<int>> dp;
int ans = 0;
void dfs(int node, int parent = -1){
    dp[node][0] = dp[node][1] = fuel[node];
    vector<int> temp;
    for(auto it : adj[node]){
        if(it.first == parent) continue;
        dfs(it.first, node);
        temp.push_back(dp[it.first][0] - it.second);
    }
    srtrev(temp);
    if(!temp.empty()) dp[node][0] = max(dp[node][0], temp[0] + fuel[node]);
    if(temp.size() > 1) dp[node][1] = max(dp[node][1], temp[0] + temp[1] + fuel[node]);
    ans = max(ans, max(dp[node][0], dp[node][1]));
}

void solve(){
    cin >> n;
    adj.assign(n + 1, vector<pair<int, int>>());
    fuel.assign(n + 1, 0);
    dp.assign(n + 1, vector<int>(2, 0));
    for(int i = 1; i <= n; i++) cin >> fuel[i];
    for(int i = 0; i < n - 1; i++){
        int u, v, w; cin >> u >> v >> w;
        adj[u].push_back({v, w});
        adj[v].push_back({u, w});
    }
    dfs(1);
    cout << ans << endl;
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
 