/* Author: Mathavaroopan */
#include "bits/stdc++.h"
#define int long long
#define srt(arr) sort(arr.begin(), arr.end())
using namespace std;

void solve(){
    int n;
    cin >> n;
    int prev = -1;
    vector<int> arr(n);
    for(int& a : arr) cin >> a;
    int l = 0, r = 0;
    int ans = 0;
    while(l < n && r < n){
        int mx = -1e17;
        if(arr[l] > 0){
            while(arr[r] > 0 && r < n){
                mx = max(arr[r], mx);
                r++;
            }
            ans += mx;
        }else{
            while(arr[r] < 0 && r < n){
                mx = max(mx, arr[r]);
                r++;
            }
            ans += mx;
        }
        l = r;
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
 