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
vector<vector<pair<int, int>>> g, g1;
bool dfs(int node, set<int>& nodes, vector<int>& vis){
    vis[node] = 1;
    if(nodes.count(node)) return true;
    for(auto [v, w] : g[node]){
        if(!vis[v] && dfs(v, nodes, vis)) return true;
    }
    return false;
}

void dfsforone(int node, vector<int>& one){
    one[node] = 1;
    for(auto [v, w] : g1[node]) if(!one[v]) dfsforone(v, one);
}

void solve(){
    int n, m;
    cin >> n >> m;
    vector<vector<int>> arr;
    g.resize(n);
    g1.resize(n);
    for(int i = 0; i < m; i++){
        int u, v, w; cin >> u >> v >> w; u--, v--;
        arr.push_back({u, v, w});
        g[v].push_back({u, w});
        g1[u].push_back({v, w});
    }
    vector<int> dist(n, -inf), vis(n, 0), one(n, 0);
    dfsforone(0, one);
    dist[0] = 0;
    set<int> nodes;
    for(int i = 0; i < n; i++){
        for(auto it : arr){
            int u = it[0], v = it[1], w = it[2];
            if(i == n - 1 && dist[v] < dist[u] + w && one[v]){
                nodes.insert(v);
            }   
            dist[v] = max(dist[v], dist[u] + w);
        }
    }
    if(dfs(n - 1, nodes, vis)) cout << -1 << endl;
    else cout << dist[n - 1] << endl;
}
 
int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int T = 1;
    while (T--) solve();
    return 0;
}
 