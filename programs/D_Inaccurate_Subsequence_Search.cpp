#include "bits/stdc++.h"
#define int long long
using namespace std;

void solve(){
    int n, m, k;
    cin >> n >> m >> k;
    vector<int> arr(n), brr(m), ok(n, 0);
    map<int, int> mp;
    for(int& a : arr) cin >> a;
    for(int& b : brr){
        cin >> b;
        mp[b]++;
    }
    int ans = 0, cur = 0;
    for(int i = 0; i < m; i++){
        if(mp[arr[i]]){
            mp[arr[i]]--;
            ok[i] = 1;
            cur++;
        }
    }
    if(cur >= k) ans++;
    for(int l = 1, r = m; r < n; l++, r++){
        if(ok[l - 1]) mp[arr[l - 1]]++;
        cur -= ok[l - 1];
        if(mp[arr[r]]){
            mp[arr[r]]--;
            ok[r] = 1;
            cur++;
        }
        if(cur >= k) ans++;
    }
    cout << ans << endl;
}

int32_t main()
{
 
 ios_base::sync_with_stdio(false);
 cin.tie(NULL);

    int T = 1;
    cin >> T;
    while (T--)
    {
        solve();
    }
    return 0;
}

    