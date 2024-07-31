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
#define sum(arr) accumulate(arr.begin(), arr.end(), 0LL)
#define endl '\n'
using namespace std;

const int mod = 1e9 + 7;
int inf = 1e18;

void solve(){
    int n;
    cin >> n;
    map<int, int> mp, next, mp2;
    int mx = 0;
    int ans = 0;
    vector<int> arr(n), arr2(n);
    for(int i = 0; i < n; i++){
        int a; cin >> a;
        mp[a]++;
        ans += a;
        if(mp[a] >= 2) mx = max(mx, a);
        arr[i] = mx;
    }
    mx = 0;
    for(int i = 0; i < n; i++){
        mp2[arr[i]]++;
        ans += arr[i];
        if(mp2[arr[i]] >= 2) mx = max(mx, arr[i]);
        arr2[i] = mx;
    }
    int s = sum(arr2), r = n - 1;
    while(s && r >= 0){
        ans += s;
        s -= arr2[r--];
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
 