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

void solve(){
    int n, m;
    cin >> n >> m;
    vector<vector<int>> arr;
    for(int i = 0; i < m; i++){
        int u, v, w; cin >> u >> v >> w; u--, v--;
        arr.push_back({u, v, w});
    }
    vector<int> dist(n, -inf);
    dist[0] = 0;
    for(int i = 0; i < n; i++){
        for(auto it : arr){
            int u = it[0], v = it[1], w = it[2];
            if(i == n - 1 && dist[v] < dist[u] + w && v == n - 1){
                cout << -1 << endl;
                return;
            }   
            dist[v] = max(dist[v], dist[u] + w);
        }
    }
    cout << dist[n - 1] << endl;
}
 
int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int T = 1;
    while (T--) solve();
    return 0;
}
 