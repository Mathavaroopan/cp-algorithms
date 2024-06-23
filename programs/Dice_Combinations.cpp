#include "bits/stdc++.h"
using namespace std;

#define int long long

int mod = 1e9 + 7;

void solve(){
    int n;
    cin >> n;    
    vector<int> dp(n + 1, 0);
    dp[0] = 1;

    for(int i = 1; i <= n; i++){
        for(int j = 0; j <= 6; j++){
            if(i >= j) dp[i] = ( dp[i] + dp[i - j] ) % mod;
        }
    }
    cout << dp[n] % mod << endl;
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

    