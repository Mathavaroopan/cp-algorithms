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
    vector<vector<int>> arr(n);
    for(int i = 0; i < m; i++){
        int u, v; cin >> u >> v; u--, v--;
        arr[u].push_back(v);
        arr[v].push_back(u);
    }
    vector<int> vis(n, -1);
    queue<int> q;
    q.push(0);
    vis[0] = -2;
    while(!q.empty()){
        int node = q.front();
        q.pop();
        if(node == n - 1) break;
        for(int x : arr[node]){
            if(vis[x] == -1){
                vis[x] = node;
                q.push(x);
            }
        }
    }
    if(vis[n - 1] == -1) cout << "IMPOSSIBLE" << endl;
    else{
        vector<int> path;
        int cur = n - 1;
        while(vis[cur] != -2){
            path.push_back(vis[cur] + 1);
            cur = vis[cur];
        }
        reverse(path);
        path.push_back(n);
        cout << path.size() << endl;
        print(path);
    }
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
 