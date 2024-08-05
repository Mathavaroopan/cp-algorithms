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
#define max(arr) *max_element(arr.begin(), arr.end())
#define sum(arr) accumulate(arr.begin(), arr.end(), 0)
#define endl '\n'
using namespace std;

const int mod = 1e9 + 7;
int inf = 1e18;

void solve(){
    int n, m, q;
    cin >> n >> m >> q;
    vector<vector<int>> arr(n, vector<int>(n, inf));
    for(int i = 0; i < n; i++) arr[i][i] = 0;
    for(int i = 0; i < m; i++){
        int u, v, w; cin >> u >> v >> w; u--, v--;
        arr[u][v] = min(arr[u][v], w);
        arr[v][u] = min(arr[v][u], w);
    }
    for(int k = 0; k < n; k++){
        for(int i = 0; i < n; i++){
            for(int j = 0; j < n; j++){
                arr[i][j] = min(arr[i][j], arr[i][k] + arr[k][j]);
            }
        }
    }
    while(q--){
        int u, v; cin >> u >> v; u--, v--;
        if(arr[u][v] >= inf) cout << -1 << endl;
        else cout << arr[u][v] << endl;
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
 