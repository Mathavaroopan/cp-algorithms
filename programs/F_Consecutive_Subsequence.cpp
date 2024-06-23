#include "bits/stdc++.h"
using namespace std;

void solve(){
    int n, len = 0, start = 0;
    cin >> n;
    vector<int> arr(n);
    for(int& a : arr) cin >> a;
    map<int, int> dp;
    for(int a : arr){
        dp[a] = 1 + dp[a - 1];
        if(dp[a] > len){
            len = dp[a];
            start = a - len + 1;
        }
    }
    cout << len << endl;
    for(int i = 0; i < n; i++){
        if(arr[i] == start){
            cout << i + 1 << " ";
            start++;
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

    