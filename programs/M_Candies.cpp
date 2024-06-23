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
#define max(arr) *max_element(arr.begin(), arr.end())
#define sum(arr) accumulate(arr.begin(), arr.end(), 0)
#define endl '\n'
using namespace std;

const int mod = 1e9 + 7;
int inf = 1e18;

void solve(){
    int n, k;
    cin >> n >> k;
    vector<int> arr(n);
    for(int& a : arr) cin >> a;
    if(k == 0){
        cout << 1 << endl;
        return;
    }
    vector<int> prev(k + 1, 0), cur(k + 1, 0);
    for(int i = 0; i <= arr[0]; i++) prev[i] = 1;
    cur = prev;
    for(int i = 1; i < n; i++){
        for(int j = 1; j <= k; j++) prev[j] = (prev[j] + prev[j - 1]) % mod;
        for(int total = 0; total <= k; total++){
            cur[total] = prev[total];
            if(total - arr[i] - 1 >= 0) cur[total] = (cur[total] + mod - prev[total - arr[i] - 1]) % mod;
        }
        prev = cur;
    }
    cout << cur[k] << endl;
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
 