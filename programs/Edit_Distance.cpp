/* Author: Mathavaroopan */
#include "bits/stdc++.h"
#define int long long
#define endl '\n'
using namespace std;

const int mod = 1e9 + 7;
int inf = 1e18;
void solve(){
    string a, b;
    cin >> a >> b;
    int n = a.size(), m = b.size();
    vector<int> prev(m + 1, 0), cur(m + 1, 0);
    for(int i = 1; i <= m; i++) prev[i] = i;
    cur = prev;
    for(int i = 1; i <= n; i++){
        cur[0] = i;
        for(int j = 1; j <= m; j++){
            if(a[i - 1] == b[j - 1]) cur[j] = prev[j - 1];
            else cur[j] = 1 + min(cur[j - 1], min(prev[j], prev[j - 1]));
        }
        prev = cur;
    }
    cout << cur[m] << endl;
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
 