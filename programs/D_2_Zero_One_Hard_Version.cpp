/* Author: Mathavaroopan */
#include "bits/stdc++.h"
#define int long long
#define srt(arr) sort(arr.begin(), arr.end())
using namespace std;

void solve(){
    int n, x, y; 
    cin >> n >> x >> y;
    int l = 0, r = n - 1;
    string s, t;
    cin >> s >> t;
    int ans = 0;
    vector<int> pos;
    for(int i = 0; i < n; i++){
        if(s[i] != t[i]){
            pos.push_back(i);
        }
    }
    if(pos.size() & 1) cout << -1 << endl;
    else{
        if(pos.size() == 2 && pos[0] + 1 == pos[1]) cout << min(x, 2 * y) << endl;
        else cout << y * (pos.size()/2) << endl;
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
 