#include <bits/stdc++.h>
#define int long long
using namespace std;

void solve(){
    int n, k;
    cin >> n >> k;
    vector<int> arr(n);
    int ans = 0;
    for(int i = 0; i < n; i++){
        cin >> arr[i];
        ans += arr[i] / k;
        arr[i] %= k;
    }
    sort(arr.begin(), arr.end());
    int l = 0, r = n - 1;
    while(l < r){
        if((arr[l] + arr[r]) / k >= 1) ans++, l++, r--;
        else l++;
    }
    cout << ans << endl;
}
 
int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int T;
    cin >> T;
    while (T--) solve();
    return 0;
}
