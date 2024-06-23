/* Author: Mathavaroopan */
#include "bits/stdc++.h"
#define int long long
#define srt(arr) sort(arr.begin(), arr.end())
using namespace std;

void solve(){
    int n, x;
    cin >> n >> x;
    int needpos = 0, needneg = 0;
    bool status = false;
    for(int i = 0; i < n; i++){
        int a; cin >> a;
        if(x >= a) needpos += x - a;
        else needneg += a - x;
        if(a == x) status = true;
    }
    if(needpos == 0 && needneg == 0) cout << 0 << endl;
    else if(needpos == needneg || status) cout << 1 << endl;
    else cout << 2 << endl;
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
 