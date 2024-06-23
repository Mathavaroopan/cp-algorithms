#include "bits/stdc++.h"
#define int long long
using namespace std;

void solve(){
    int n;
    cin >> n;
    vector<int> arr(n);
    for(int i = 0; i < n; i++) cin >> arr[i];
    sort(arr.begin(), arr.end());
    int min_diff = INT_MAX;
    for(int i = 1; i < n; i++){
        min_diff = min(arr[i] - arr[i - 1], min_diff);
    }
    int i = 1;
    for(i = 1; i < n; i++){
        if(arr[i] - arr[i - 1] == min_diff) break;
    }
    vector<int> ans(n);
    ans[0] = arr[i - 1];
    ans[n - 1] = arr[i];
    int k = 1;
    for(int j = i + 1; j < n; j++, k++){
        ans[k] = arr[j];
    }
    for(int j = 0; j < i - 1; j++, k++){
        ans[k] = arr[j];
    }
    for(int a : ans) cout << a << " ";
    cout << endl;
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

    