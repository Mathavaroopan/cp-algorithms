/* Author: Mathavaroopan */
#include "bits/stdc++.h"
#define int long long
#define srt(arr) sort(arr.begin(), arr.end())
using namespace std;
const int mod = 1e9 + 7;
void solve(){
    int n, k;
    cin >> n >> k;
    vector<int> arr(n), prev(k + 1, 0), cur(k + 1, 0);
    for(int& a : arr) cin >> a;
    for(int sum = 0; sum <= k; sum++) if(sum % arr[0] == 0) prev[sum] = 1;
    cur = prev;
    for(int i = 1; i < n; i++){
        for(int sum = 0; sum <= k; sum++){
            cur[sum] = prev[sum];
            if(sum >= arr[i]) cur[sum] += cur[sum - arr[i]];
            cur[sum] %= mod;
        }
        prev = cur;
    }    
    cout << prev[k] << endl;
}
 
int32_t main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int T = 1;
    while (T--) solve();
    return 0;
}
 