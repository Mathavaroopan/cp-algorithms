/* Author: Mathavaroopan */
#include "bits/stdc++.h"
#define int long long
#define double long double
#define srt(arr) sort(arr.begin(), arr.end())
#define srtrev(arr) sort(arr.begin(), arr.end(), greater<int>())
#define reverse(arr) reverse(arr.begin(), arr.end())
#define all(arr) arr.begin(), arr.end()
#define input(arr) for(int& a : arr) cin >> a
#define print(arr) for(int i : arr) cout << i << " "
#define var(a) cout << #a << " = " << a << endl
#define min(arr) *min_element(arr.begin(), arr.end())
#define sum(arr) accumulate(arr.begin(), arr.end(), 0)
#define endl '\n'
using namespace std;

const int mod = 1e9 + 7;
int inf = 1e18;
vector<int> arr(5000);
vector<vector<int>> dp(5000, vector<int>(5000, -1));
int go(int L, int R){
    if(L > R)
        return 0;

    if(dp[L][R] != -1) return dp[L][R];
    
    int c1 = arr[L] - go(L + 1, R);
    int c2 = arr[R] - go(L, R - 1);

    return dp[L][R] = max(c1, c2);
}

void solve(){
    int n;
    cin >> n;
    vector<vector<int>> dp(n, vector<int>(n, 0));
    for(int i = 0; i < n; i++){
        cin >> arr[i];
        dp[i][i] = arr[i];
    }
    for(int l = n - 1; l >= 0; l--){
        for(int r = l + 1; r < n; r++){
            dp[l][r] = max(arr[l] - dp[l + 1][r], arr[r] - dp[l][r - 1]);
        }
    }
    for(auto v : dp){
        print(v);
        cout << endl;
    }
    cout << go(0, n - 1) << endl;
    cout << dp[0][n - 1] << endl;
}
 
int32_t main()
{
 
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
 
    int T = 1;
    // cin >> T;
    while (T--) solve();
    return 0;
}
 