#include "bits/stdc++.h"
#define int long long
using namespace std;

void solve(){
    int n, x;
    cin >> n >> x;
    vector<int> arr(n);
    for(int i = 0; i < n; i++) cin >> arr[i];
    int i = 0, j = 0, ans = 0, sum = 0;
    while(j < n){
        sum += arr[j];
        while(sum >= x){
            if(sum == x) ans++;
            sum -= arr[i];
            i++;
        }
        j++;
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

    