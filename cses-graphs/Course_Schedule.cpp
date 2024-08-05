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

void solve(){
    int n, m;
    cin >> n >> m;
    vector<vector<int>> g(n);
    vector<int> indegree(n, 0);
    for(int i = 0; i < m; i++){
        int u, v; cin >> u >> v; u--, v--;
        g[u].push_back(v);
        indegree[v]++;
    }
    vector<int> topo;
    queue<int> q;
    for(int i = 0; i < n; i++){
        if(indegree[i] == 0) q.push(i);
    }
    while(!q.empty()){
        int node = q.front(); q.pop();
        topo.push_back(node + 1);
        for(int x : g[node]){
            if(--indegree[x] == 0) q.push(x);
        }
    }
    if(topo.size() == n) print(topo);
    else cout << "IMPOSSIBLE" << endl;
}
 
int32_t main()
{
 
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
 
    int T = 1;
    while (T--) solve();
    return 0;
}
 