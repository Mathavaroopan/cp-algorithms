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
vector<int> dp;
vector<vector<int>> arr;
void dfs(int node, int parent = -1){
    for(int v : arr[node]){
        if(v == parent) continue;
        dfs(v, node);
        dp[node] += dp[v] + 1;
    }
}

void solve(){
    int n; cin >> n;
    arr.resize(n);
    dp.assign(n, 0);
    for(int i = 0; i < n - 1; i++){
        int u; cin >> u;
        arr[--u].push_back(i + 1);
        arr[i + 1].push_back(u);
    }
    dfs(0);
    print(dp);
}
 
int32_t main()
{
 
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
 
    int T = 1;
    while (T--) solve();
    return 0;
}
 