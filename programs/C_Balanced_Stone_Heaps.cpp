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
#define sum(arr) accumulate(arr.begin(), arr.end(), 0)
#define endl '\n'
using namespace std;

const int mod = 1e9 + 7;
int inf = 1e18;

void solve(){
    int n; cin >> n;
    vector<int> arr(n);
    input(arr);
    int low = 0, high = 1e9, ans = 0;
    while(low <= high){
        int mid = low + (high - low) / 2, p2 = 0, p1 = 0, cur = 0;
        bool ok = true;
        for(int i = n - 1; i >= 2; i--){
            int d = arr[i] - max(mid - p1, 0LL);
            if(d < 0){
                ok = false;
                break;
            }
            d /= 3;
            p1 = p2 + d;
            p2 = 2 * d;
        }
        if(ok && arr[0] + p2 >= mid && arr[1] + p1 >= mid){
            ans = mid;
            low = mid + 1;
        }else high = mid - 1;
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
 