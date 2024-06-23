#include "bits/stdc++.h"
using namespace std;

void solve(){
    int n;
    cin >> n;
    stack<pair<int, int>> s;
    for(int i = 0; i < n; i++){
        int a;
        cin >> a;
        while(!s.empty()){
            if(s.top().first >= a) s.pop();
            else{
                cout << s.top().second << " ";
                s.push({a, i + 1});
                break;
            }
        }
        if(s.empty()){
            cout << 0 << " ";
            s.push({a, i + 1});
        }
    }
}

int32_t main()
{
 
 ios_base::sync_with_stdio(false);
 cin.tie(NULL);

    int T = 1;
    while (T--)
    {
        solve();
    }
    return 0;
}

    