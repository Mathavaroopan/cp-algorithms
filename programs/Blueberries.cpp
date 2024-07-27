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

int dp[1003][1003];
int arr[1003];
int n;
int fun(int i, int w){
    if(w < 0) return -1e9;
    if(i >= n) return 0;
    if(dp[i][w] != -1) return dp[i][w];
    return dp[i][w] = max(fun(i + 1, w), arr[i] + fun(i + 2, w - arr[i]));
}
void solve(int t){
    int w;
    cin >> n >> w;
    for(int i = 0; i < n; i++) cin >> arr[i];
    memset(dp, -1, sizeof(dp));
    cout << "Scenario #" << t << ": " << fun(0, w) << endl;
}
 
int32_t main()
{
 
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
 
    int T = 1;
    cin >> T;
    int i = 1;
    while (i <= T) solve(i++);
    return 0;
}
 