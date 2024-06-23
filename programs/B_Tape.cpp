/* Author: Mathavaroopan */
#include "bits/stdc++.h"
#define int long long
#define srt(arr) sort(arr.begin(), arr.end())
using namespace std;

void solve(){
    int n, m, k;
    cin >> n >> m >> k;
    vector<int> arr(n);
    for(int& a : arr) cin >> a;
    int low = 0, high = m, ans = 0;
    while(low <= high){
        int mid = (low + high)/2;
        bool check = false;
        int cur = arr[0] + mid - 1;
        for(int i = 0; i < k - 1; i++){
            int ind = upper_bound(arr.begin(), arr.end(), cur) - arr.begin();
            if(ind == n){
                check = true;
                break;
            }
            cur = arr[ind] + mid - 1;
        }
        if(check){
            ans = mid;
            high = mid - 1;
        }else low = mid + 1;
    }
    cout << ans << endl;
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
 