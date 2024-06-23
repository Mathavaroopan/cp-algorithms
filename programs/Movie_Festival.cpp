#include "bits/stdc++.h"
#define int long long
using namespace std;

void solve(){
    int n;
    cin >> n;
    pair<int, int> arr[n];
    for(int i = 0; i < n; i++){
        int a, b;
        cin >> a >> b;
        arr[i] = {b, a};
    }
    sort(arr, arr + n);
    int ans = 1;
    int finish = arr[0].first;
    for(int i = 1; i < n; i++){
        if(arr[i].second >= finish){
            ans++;
            finish = arr[i].first;
        }
    }
    cout << ans << endl;
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

    