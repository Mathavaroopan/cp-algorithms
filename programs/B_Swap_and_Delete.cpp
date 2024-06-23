/* Author: Mathavaroopan */
#include "bits/stdc++.h"
#define int long long
#define srt(arr) sort(arr.begin(), arr.end())
using namespace std;

void solve(){
    string s;
    cin >> s;
    map<char, queue<int>> mp;
    for(int i = 0; i < n; i++){
        mp[s[i]].push_back(i);
    }
    int ans = 0, n = s.size();
    for(int i = 0; i < n; i++){
        if(s[i] == '1'){
            if(mp['0'] == 0){
                ans = n - i;
                break;
            }
            mp['0']--;
        }else{
            if(mp['1'] == 0){
                ans = n - i;
                break;
            }
            mp['1']--;
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
 