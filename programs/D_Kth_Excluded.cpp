#include "bits/stdc++.h"
#define int long long
using namespace std;

void solve(){
    int n, t;
    cin >> n >> t;
    vector<int> arr(n);
    sort(arr.begin(), arr.end());
    for(int& a : arr) cin >> a;
    while(t--){
        int k; cin >> k;
        int l = 0, r = 1e19;
        while(r - l > 1){
            int mid = (l + r)/2;
            
        }
    }
}

int32_t main()
{
 
 ios_base::sync_with_stdio(false);
 cin.tie(NULL);

    int T = 1;
    // cin >> T;
    while (T--)
    {
        solve();
    }
    return 0;
}

    