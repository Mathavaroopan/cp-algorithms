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
int n, m;
vector<vector<int>> g;
vector<int> vis, pathvis;
bool dfs(int node, int parent = -2){
    pathvis[node] = parent;
    vis[node] = 1;
    for(int v : g[node]){
        if(!vis[v]){
            if(dfs(v, node)) return true;
        }else if(pathvis[v] != -1) {
            int cur = node;
            vector<int> ans = {v + 1};
            while(cur != v){
                ans.push_back(cur + 1);
                cur = pathvis[cur];
            }
            ans.push_back(v + 1);
            reverse(ans);
            cout << ans.size() << endl;
            print(ans);
            return true;
        }
    }
    pathvis[node] = -1;
    return false;
}

void solve(){
    cin >> n >> m;
    vis.assign(n, 0);
    pathvis.assign(n, -1);
    g.resize(n);
    for(int i = 0; i < m; i++){
        int u, v; cin >> u >> v; u--, v--;
        g[u].push_back(v);
    }
    for(int i = 0; i < n; i++){
        if(!vis[i] && dfs(i)) return;
    }
    cout << "IMPOSSIBLE" << endl;
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
 