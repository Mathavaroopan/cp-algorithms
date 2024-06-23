/* Author: Mathavaroopan */
#include "bits/stdc++.h"
#define int long long
#define srt(arr) sort(arr.begin(), arr.end())
using namespace std;

void solve(){
    int n, w;
    cin >> n >> w;
    map<int, int> mp;
    for(int i = 0; i < n; i++){
        int a; cin >> a;
        mp[a]++;
    }
    int ans = 0, curw = 0;
    while(mp.size()){
        auto it = mp.upper_bound(curw);
        if(it == mp.begin()){
            ans++;
            curw = w;
        }else{
            it--;
            curw -= it->first;
            it->second--;
            if(it->second == 0) mp.erase(it);
        }
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
 