/* Author: Mathavaroopan */
#include "bits/stdc++.h"
#define int long long
#define srt(arr) sort(arr.begin(), arr.end())
using namespace std;

void solve(){
    int n, m;
    cin >> n >> m;
    vector<int> arr(n), c(m);
    for(int& a : arr){
        cin >> a;
        a--;
    }
    for(int& i : c) cin >> i;
    sort(arr.begin(), arr.end(), greater<int>());
    int cur = 0, ans = 0;
    for(int i : arr){
        if(cur <= i) ans += c[cur++];
        else ans += c[i];
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
 