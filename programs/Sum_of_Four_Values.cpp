#include "bits/stdc++.h"
#define int long long
using namespace std;

void solve(){
    int n, sum;
    cin >> n >> sum;
    vector<int> arr(n);
    for(int i = 0; i < n; i++) cin >> arr[i];
    map<int, pair<int, int>> mp;
    for(int i = 0; i < n; i++){
        for(int j = i + 1; j < n; j++){
            int target = sum - arr[i] - arr[j];
            if(mp.count(target)){
                cout << i + 1 << " " << j + 1 << " " << mp[target].first + 1 << " " << mp[target].second + 1 << endl;
                return;
            }
        }
        for(int k = 0; k < i; k++) mp[arr[i] + arr[k]] = {i, k};
    }
    cout << "IMPOSSIBLE" << endl;
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

    