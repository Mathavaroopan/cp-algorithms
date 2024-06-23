/* Author: Mathavaroopan */
#include "bits/stdc++.h"
#define int long long
#define srt(arr) sort(arr.begin(), arr.end())
using namespace std;

void solve(){
    int n; cin >> n;
    vector<int> arr(n), lis, ind, bal;
    for(int& a : arr) cin >> a;
    reverse(arr.begin(), arr.end());
    for(int i = 0; i < n; i++){
        if(lis.empty() || lis.back() <= arr[i]){
            lis.push_back(arr[i]);
            ind.push_back(i);
        }
        else{
            auto it = lower_bound(lis.begin(), lis.end(), arr[i]);
            *it = arr[i];
            ind[it - lis.begin()] = i;
        }
    }
    sort(ind.begin(), ind.end());
    int ans = 0;
    for(int i = 0; i < n; i++){
        if(!binary_search(ind.begin(), ind.end(), i)) bal.push_back(arr[i]);
    }
    for(int i = 0; i < (int) bal.size() - 1; i++){
        if(bal[i] > bal[i + 1]) ans++;
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
 