/* Author: Mathavaroopan */
#include "bits/stdc++.h"
#define int long long
#define srt(arr) sort(arr.begin(), arr.end())
using namespace std;

void solve(){
    int n, q;
    cin >> n >> q;
    vector<int> arr(n + 1, 0);
    for(int i = 0; i < n; i++) cin >> arr[i];
    int mn = 1, mx = 0, ans = 0;
    while(mn <= n){
        while(arr[mx] < arr[mn]) mx++, mn++;
        while(mn + 1 <= n && arr[mn] > arr[mn + 1]) mn++;
        if(mn <= n && arr[mx] > arr[mn]){
            ans += arr[mx] - arr[mn];
            mx = mn + 1;
            mn = mx + 1;
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
 