/* Author: Mathavaroopan */
#include "bits/stdc++.h"
#define int long long
#define srt(arr) sort(arr.begin(), arr.end())
using namespace std;

void solve(){
    int n, q;
    cin >> n >> q;
    vector<int> pref(n + 1, 1);
    int prev = -1, p = -1;
    for(int i = 0; i < n; i++){
        int a; cin >> a;
        if(prev <= a){
            prev = a;
            p = -1;
        }
        else{
            prev = a;
            if( )
            p = i;
        }
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
 