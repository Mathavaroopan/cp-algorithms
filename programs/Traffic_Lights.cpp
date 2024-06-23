#include "bits/stdc++.h"
#define int long long
using namespace std;
void solve(){
    int n, m;
    cin >> n >> m;
    map<int, int> mp;
    set<int> s;
    s.insert(0);
    s.insert(n);
    mp[n]++;
    for(int i = 0; i < m; i++){
        int a;
        cin >> a;
        auto up = s.upper_bound(a);
        auto lo = up;
        lo--;
        int diff = *up - *lo;
        mp[diff]--;
        if(mp[diff] == 0){
            auto temp = mp.lower_bound(diff);
            mp.erase(temp);
        }
        mp[*up - a]++;
        mp[a - *lo]++;
        auto it = mp.rbegin();
        cout << it->first << " ";
        s.insert(a);
    }   
    cout << endl;
}

int32_t main()
{
 
 ios_base::sync_with_stdio(false);
 cin.tie(NULL);

    int T = 1;
    // cin >> T;
    while (T--)
    {
        solve();
    }
    return 0;
}

    
    