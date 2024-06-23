/* Author: Mathavaroopan */
#include "bits/stdc++.h"
#define int long long
#define srt(arr) sort(arr.begin(), arr.end())
using namespace std;

void solve(){
    int n, k, q;
    cin >> n >> k >> q;
    vector<int> arr(k + 1, 0), brr(k + 1, 0);
    for(int i = 1; i <= k; i++) cin >> arr[i];
    for(int i = 1; i <= k; i++) cin >> brr[i];
    while(q--){
        int p;
        cin >> p;
        int index = lower_bound(arr.begin(), arr.end(), p) - arr.begin();
        if(arr[index] == p) cout << brr[index] << " ";
        else{
            int ans = brr[index - 1];
            int dist = arr[index] - arr[index - 1];
            int time = brr[index] - brr[index - 1];
            int speed = dist/time;
            ans += (int)((p - arr[index - 1])/speed);
            cout << ans << " ";
        }
    }
    cout << endl;
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
 