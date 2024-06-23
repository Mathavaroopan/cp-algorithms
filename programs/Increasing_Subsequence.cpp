#include "bits/stdc++.h"
using namespace std;

void solve(){
    int n;
    cin >> n;
    int arr[n];
    for(int i = 0; i < n; i++) cin >> arr[i];
    int insertedat[n];
    vector<int> lis;
    for(int i = 0; i < n; i++){
        if(lis.empty() || lis.back() < arr[i]){
            lis.push_back(arr[i]);
            insertedat[i] = lis.size();
        }else{
            auto it = lower_bound(lis.begin(), lis.end(), arr[i]);
            *it = arr[i];
            insertedat[i] = it - lis.begin() + 1;
        }
    }
    int curlen = lis.size();
    vector<int> ans(lis.size());
    for(int i = n - 1; i >= 0; i--){
        if(insertedat[i] == curlen){
            ans[--curlen] = arr[i];
        }
    }
    cout << ans.size() << endl;
    for(int i : ans) cout << i << " ";
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

    