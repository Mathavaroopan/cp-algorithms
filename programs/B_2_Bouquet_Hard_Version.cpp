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
#define endl '\n'
using namespace std;

const int mod = 1e9 + 7;
int inf = 1e18;

void solve(){
    int n, m;
    cin >> n >> m;
    map<int, int> mp;
    vector<int> arr(n);
    input(arr);
    for(int i = 0; i < n; i++){
        int a; cin >> a;
        mp[arr[i]] = a;
    }
    int ans = 0;
    for(auto it : mp){
        int l = 0, r = 0, b = it.second - 1, cur = 0, limit = 0;
        if(mp.find(it.first + 1) != mp.end()) limit = mp[it.first + 1];
        while(r < it.second + limit && l <= r){
            if(cur + ((r <= b) ? it.first : it.first + 1) <= m) cur += ((r++ <= b) ? it.first : it.first + 1);
            else cur -= ((l++ <= b) ? it.first : it.first + 1);
            ans = max(ans, cur);
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
 