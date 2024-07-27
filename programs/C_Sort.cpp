#include <bits/stdc++.h>
#define int long long
using namespace std;

void solve(){
    int n, q;
    cin >> n >> q;
    string a, b;
    cin >> a >> b;
    vector<vector<int>> fa(n + 1, vector<int>(26, 0)), fb(n + 1, vector<int>(26, 0));
    for(int i = 1; i <= n; i++){
        fa[i] = fa[i - 1];
        fb[i] = fb[i - 1];
        fa[i][a[i - 1] - 'a']++;
        fb[i][b[i - 1] - 'a']++;
    }
    while(q--){
        int l, r; cin >> l >> r;
        int ans = 0;
        for(int i = 0; i < 26; i++){
            ans += max(fb[r][i] - fb[l - 1][i] - (fa[r][i] - fa[l - 1][i]), 0LL);
        }
        cout << ans << endl;
    }
}
 
int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int T;
    cin >> T;
    while (T--) solve();
    return 0;
}
