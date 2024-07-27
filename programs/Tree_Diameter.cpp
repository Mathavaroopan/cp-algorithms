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
vector<vector<int>> adj;
vector<int> dp;
int ans = 0;
void dfs(int node, int parent){
    if(node != 1 && adj[node].size() == 1){
        dp[node] = 0;
        return;
    }
    for(int v : adj[node]){
        if(v == parent) continue;
        dfs(v, node);
        dp[node] = max(dp[node], dp[v] + 1);
    }
}

void calc(int node, int parent){
    if(node != 1 && adj[node].size() == 1) return;
    ans = max(ans, dp[node]);
    vector<int> temp;
    for(int v : adj[node]){
        if(v == parent) continue;
        calc(v, node);
        temp.push_back(dp[v]);
    }
    if(temp.size() <= 1) return;
    srtrev(temp);
    ans = max(ans, temp[0] + temp[1] + 2);
}

void solve(){
    cin >> n;
    adj.resize(n + 1);
    dp.assign(n + 1, 0);
    for(int i = 0; i < n - 1; i++){
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    dfs(1, -1);
    calc(1, -1);
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
 