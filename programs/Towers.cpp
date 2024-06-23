#include <bits/stdc++.h>
using namespace std;

#define int long long

void solve(){
    int n;
    cin >> n;
    multiset<int> ms;
    for(int i = 0; i < n; i++){
        int x;
        cin >> x;
        auto it = ms.upper_bound(x);
        if(it != ms.end()){
            ms.insert(x);
            ms.erase(it);
        }else{
            ms.insert(x);
        }
    }
    cout << ms.size() << endl;
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

    