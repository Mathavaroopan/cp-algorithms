/* Author: Mathavaroopan */
#include "bits/stdc++.h"
#include <iomanip>
#define int long long
#define double long double
#define srt(arr) sort(arr.begin(), arr.end())
#define srtrev(arr) sort(arr.begin(), arr.end(), greater<int>())
#define reverse(arr) reverse(arr.begin(), arr.end())
#define all(arr) arr.begin(), arr.end()
#define input(arr) for(int& a : arr) cin >> a
#define print(arr) for(auto i : arr) cout << i << " "
#define var(a) cout << #a << " = " << a << endl
#define min(arr) *min_element(arr.begin(), arr.end())
#define max(arr) *max_element(arr.begin(), arr.end())
#define sum(arr) accumulate(arr.begin(), arr.end(), 0)
#define endl '\n'
using namespace std;

const int mod = 1e9 + 7;
int inf = 1e18;

void solve(){
    int n; 
    cin >> n;
    vector<double> arr(n);
    for(int i = 0; i < n; i++) cin >> arr[i];
    vector<double> ahead(n + 1, 0), cur(n + 1, 0);
    for(int c = 0; c <= n; c++) ahead[c] = ((2 * c > n) ? 1.0 : 0.0);
    for(int i = n - 1; i >= 0; i--){
        for(int c = i; c >= 0; c--){
            cur[c] = arr[i] * ahead[c + 1] + (1 - arr[i]) * ahead[c];
        }
        ahead = cur;
    }
    cout << fixed << setprecision(10) << cur[0] << endl;
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
 