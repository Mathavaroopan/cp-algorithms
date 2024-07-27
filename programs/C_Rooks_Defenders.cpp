/* Author: Mathavaroopan */
#include "bits/stdc++.h"
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#include <functional>
using namespace __gnu_pbds;
using namespace std;
 
typedef tree<pair<int, int>, null_type, less<pair<int, int> >,
             rb_tree_tag, tree_order_statistics_node_update>
    ordered_map;
const int mod = 1e9 + 7;
int inf = 1e18;

void solve(){
    set<int> row, col;
    int n, q; cin >> n >> q;
    vector<int> rowf(n + 1, 0), colf(n + 1, 0);
    for(int i = 1; i <= n; i++){
        row.insert(i);
        col.insert(i);
    }
    while(q--){
        int type; cin >> type;
        if(type == 1){
            int x, y; cin >> x >> y;
            rowf[x]++;
            colf[y]++;
            row.erase(x);
            col.erase(y);
        }else if(type == 2){
            int x, y; cin >> x >> y;
            rowf[x]--;
            colf[y]--;
            if(rowf[x] == 0) row.insert(x);
            if(colf[y] == 0) col.insert(y);
        }else{
            int x1, y1, x2, y2;
            cin >> x1 >> y1 >> x2 >> y2;
            int lr = 1e9, lc = 1e9;
            auto it1 = row.lower_bound(x1);
            auto it2 = col.lower_bound(y1);
            if(it1 != row.end()) lr = *it1;
            if(it2 != col.end()) lc = *it2;
            if(lr > x2 || lc > y2) cout << "Yes" << endl;
            else cout << "No" << endl;
        }
    }
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
 