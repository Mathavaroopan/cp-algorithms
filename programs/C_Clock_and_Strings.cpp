/* Author: Mathavaroopan */
#include "bits/stdc++.h"
#define int long long
#define srt(arr) sort(arr.begin(), arr.end())
using namespace std;

void solve(){
    int a, b, c, d;
    cin >> a >> b >> c >> d;
    if(a > b) swap(a, b);    
    int cnt = 0;
    int k = abs(a - b);
    for(int i = a + 1, j = 0; i < b, j < k; i = (i + 1) % 12, j++){
        if(c == i) cnt++;
        if(d == i) cnt++;
    }
    if(cnt == 1) cout << "YES" << endl;
    else cout << "NO" << endl;
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
 