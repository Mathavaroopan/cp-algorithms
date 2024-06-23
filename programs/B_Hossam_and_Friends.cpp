/* Author: Mathavaroopan */
#include "bits/stdc++.h"
#define int long long
#define srt(arr) sort(arr.begin(), arr.end())
using namespace std;

void solve(){
    int n, m;
    cin >> n >> m;
    vector<vector<int>> arr(n);
    vector<int> mp(n, 0);
    for(int i = 0; i < m; i++){
        int u, v;
        cin >> u >> v;
        u--, v--;
        arr[u].push_back(v);
        arr[v].push_back(u);
    }
    int l = 0, r = 0, ans = 0;
    while(r < n){
        while(mp[r]){
            for(int j : arr[l]) mp[j]--;
            l++;
        }
        for(int i : arr[r]) mp[i]++;
        ans += r - l + 1;
        r++;
    }
    cout << ans << endl;
}
 
int32_t main()
{
 
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
 
    int T = 1;
    cin >> T;
    while (T--) solve();
    return 0;
}
 