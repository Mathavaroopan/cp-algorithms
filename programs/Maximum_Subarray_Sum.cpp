#include "bits/stdc++.h"
#define int long long
using namespace std;

void solve(){
    int n;
    cin >> n;
    int arr[n];
    for(int i = 0; i < n; i++) cin >> arr[i];
    int i = 0, ans = INT_MIN, cur = 0;
    while(i < n){
        cur += arr[i];
        ans = max(ans, cur);
        if(cur < 0) cur = 0;
        i++;
    }
    cout << ans << endl;
}

int32_t main()
{
 
 ios_base::sync_with_stdio(false);
 cin.tie(NULL);

    int T = 1;
    while (T--)
    {
        solve();
    }
    return 0;
}

    