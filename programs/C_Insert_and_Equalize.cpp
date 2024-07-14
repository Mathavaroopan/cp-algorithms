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
    int n;
    cin >> n;
    vector<int> arr(n);
    input(arr);
    if(n == 1){
        cout << 1 << endl;
        return;
    }
    srt(arr);
    int k = arr[n - 1] - arr[0];
    for(int i = 1; i < n - 1; i++) k = __gcd(k, arr[n - 1] - arr[i]);
    int ans = 0;
    for(int i = 0; i < n - 1; i++) ans += (arr[n - 1] - arr[i]) / k;
    for(int i = arr[n - 1] - k; ; i -= k){
        if(binary_search(arr.begin(), arr.end(), i) == false){
            ans += (arr[n - 1] - i) / k;
            break;
        }
    }
    cout << ans << endl;
}
 
int32_t main()
{
 
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
 
    int T = 1;
    cin >> T;
    while (T--) solve();
    return 0;
}
 