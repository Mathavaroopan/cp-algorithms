#include "bits/stdc++.h"
#define int long long
using namespace std;

void solve(){
    int n, w, h;
    cin >> n >> w >> h;
    vector<int> cakes(n), mh(n);
    for(int i = 0; i < n; i++) cin >> cakes[i];
    for(int i = 0; i < n; i++) cin >> mh[i];    
    vector<pair<int, int>> arr(n);
    for(int i = 0; i < n; i++){
        arr[i].first = (cakes[i] - w) - (mh[i] - h);
        arr[i].second = (cakes[i] + w) - (mh[i] + h);
    }
    int a = arr[0].first, b = arr[0].second;
    for(int i = 1; i < n; i++){
        if(!(a <= arr[i].second && arr[i].first <= b)){
            cout << "NO" << endl;
            return;
        }
    }
    cout << "YES" << endl;
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

    