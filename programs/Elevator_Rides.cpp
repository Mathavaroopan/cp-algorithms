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
#define max(arr) *max_element(arr.begin(), arr.end())
#define sum(arr) accumulate(arr.begin(), arr.end(), 0)
#define endl '\n'
using namespace std;

const int mod = 1e9 + 7;
int inf = 1e18;
// dp[i][ride] -> till ith person,
// dp[i][r] = weight of the rth ride till ith person
// dp[n - 1][j] -> find min j that works
/*
state: dp[i][r] -> min weight the rth ride will carry, till ith person
transition: f(i - 1, {arr[i], arr[i], arr[i],....})
final answer: count of set dp[n - 1] positions
*/
int n, w;
vector<int> arr(20);
vector<int> dp(20, 0);
vector<int> cur(20, -1);
int f(int i){
    if(i < 0){
        int res = 0;
        for(int i = 0; i < n; i++) res += (dp[i] > 0 ? 1 : 0);
        return res;
    }
    if(cur[i] != -1) return cur[i];
    int ans = 1e9;
    for(int j = 0; j < n; j++){
        if(dp[j] + arr[i] <= w){
            dp[j] += arr[i];
            ans = min(ans, f(i - 1));
            dp[j] -= arr[i];
        }
    }
    return cur[i] = ans;
}

void solve(){
    cin >> n >> w;
    for(int i = 0; i < n; i++) cin >> arr[i];
    cout << f(n - 1) << endl;
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
 