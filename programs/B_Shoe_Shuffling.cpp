/* Author: Mathavaroopan */
#include "bits/stdc++.h"
#define int long long
#define srt(arr) sort(arr.begin(), arr.end())
using namespace std;

void solve(){
    int n;
    cin >> n;
    map<int, vector<int>> mp;
    for(int i = 0; i < n; i++){
        int a; cin >> a;
        mp[a].push_back(i);
    }    
    for(auto it : mp){
        if(it.second.size() == 1){
            cout << -1 << endl;
            return;
        }
    }
    vector<int> ans(n);
    for(auto it : mp){
        int m = it.second.size();
        for(int i = 0; i < m/2; i++){
            ans[it.second[2*i]] = it.second[2*i + 1] + 1;
            ans[it.second[2*i + 1]] = it.second[2*i] + 1;
        }
        if(m & 1){
            ans[it.second[m - 1]] = it.second[m - 3] + 1;
            ans[it.second[m - 2]] = it.second[m - 1] + 1;
        }
    }
    for(int a : ans) cout << a << " ";
    cout << endl;
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
 