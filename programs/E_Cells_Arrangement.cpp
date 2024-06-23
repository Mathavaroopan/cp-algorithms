/* Author: Mathavaroopan */
#include "bits/stdc++.h"
#define int long long
#define srt(arr) sort(arr.begin(), arr.end())
using namespace std;

void solve(){
    int n;
    cin >> n;
    cout << 1 << " " << 1 << endl << 1 << ' ' << 2 << endl;
    for(int i = 3; i <= n; i++) cout << i << " " << i << endl;
    cout << endl;
}
 
int32_t main()
{
 
    ios_base::sync_with_stdio(false );
    cin.tie(NULL);
 
    int T = 1;
    cin >> T;
    while (T--) solve();
    return 0;
}
 