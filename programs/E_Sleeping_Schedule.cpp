#include "bits/stdc++.h"
#define int long long
using namespace std;


void solve(){
    int n, h, l, r;
    vector<int> arr(n);
    cin >>  n >> h >> l >> r;
    for(int& a : arr) cin >> a;
    vector<int> prev(h, 0), cur(h, 0);
    for(int i = n - 1; i >= 0; i--){
        for(int time = h - 1; time >= 0; time--){
            int left = prev[(time + arr[i]) % h];
            if((time + arr[i]) % h >= l && (time + arr[i]) % h <= r) left++;
            int right = prev[(time + arr[i] - 1) % h];
            if((time + arr[i] - 1) % h >= l && (time + arr[i] - 1) % h <= r) right++;
            cur[time] = max(left, right);
        }
        prev = cur;
    }
    cout << cur[0] << endl;
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

    