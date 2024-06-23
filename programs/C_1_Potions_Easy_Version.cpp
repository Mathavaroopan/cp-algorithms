/* Author: Mathavaroopan */
#include "bits/stdc++.h"
#define int long long
#define srt(arr) sort(arr.begin(), arr.end())
using namespace std;

int n;
vector<int> arr(2002);
map<pair<int, int>, int> mp;
int fun(int i, int sum){
    if(sum < 0) return 0;
    if(i == n) return 0;
    if(mp.find({i, sum}) != mp.end()) return mp[{i, sum}];
    return mp[{i, sum}] = max(1 + fun(i + 1, sum + arr[i]), fun(i + 1, sum));
}

void solve(){
    cin >> n;
    for(int i = 0; i < n; i++) cin >> arr[i];
    cout << fun(0, 0) << endl;
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
 