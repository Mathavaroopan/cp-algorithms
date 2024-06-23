/* Author: Mathavaroopan */
#include "bits/stdc++.h"
#define int long long
#define srt(arr) sort(arr.begin(), arr.end())
using namespace std;

void solve(){
    int n, k;
    cin >> n >> k;
    string s; cin >> s;
    vector<int> pos;
    for(int i = 0; i < n; i++) if(s[i] == '1') pos.push_back(i);
    if(pos.size() == 0){
        int ans = 0;
        for(int i = 0; i < n; i += k + 1){
            ans++;
        }
        cout << ans << endl;
    }else{
        int f = pos.back();
        pos.pop_back();
        int ans = 0;
        for(int i = f + k + 1; i < n; i += k + 1) ans++;
        while(pos.size()){
            int s = pos.back();
            pos.pop_back();
            for(int i = s + k + 1; i < f - k; i += k + 1) ans++;
            f = s;
        }
        for(int i = 0; i < f - k; i += k + 1) ans++;
        cout << ans << endl;
    }
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
 