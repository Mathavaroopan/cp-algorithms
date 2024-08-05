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
vector<vector<int>> arr;
vector<int> vis;

bool dfs(int node){
    for(int x : arr[node]){
        if(vis[x] == vis[node]) return false;
        if(vis[x] == -1){
            vis[x] = !vis[node];
            if(!dfs(x)) return false;
        }
    }
    return true;
}

void solve(){
    cin >> n >> m;
    arr.resize(n);
    vis.assign(n, -1);
    for(int i = 0; i < m; i++){
        int u, v; cin >> u >> v; u--, v--;
        arr[u].push_back(v);
        arr[v].push_back(u);
    }
    for(int node = 0; node < n; node++){
        if(vis[node] == -1){
            vis[node] = 1;
            if(!dfs(node)){
                cout << "IMPOSSIBLE" << endl;
                return;
            }
        }
    }
    for(int& v : vis) if(v == 0) v = 2;
    print(vis);
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
 