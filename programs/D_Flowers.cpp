#include <bits/stdc++.h>
#define int long long
#define uint unsigned long long
using namespace std;
const int mod = 1e9 + 7;

int t, k;

void solve(){
    cin >> t >> k;
    int n = 1e5;
    vector<int> dp(n + 1, 0), presum(n + 1);
    for(int i = 0; i < k; i++) dp[i] = 1;
    for(int i = k; i <= n; i++) dp[i] = (dp[i - 1] + dp[i - k]) % mod;
    for(int i = 1; i <= n; i++) presum[i] = (dp[i] + presum[i - 1]) % mod;
    while(t--){
        int a, b;
        cin >> a >> b;
        int ans = (presum[b] - presum[a - 1]) % mod;
        if(ans < 0) ans += mod;
        cout << ans << endl;
    }
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
