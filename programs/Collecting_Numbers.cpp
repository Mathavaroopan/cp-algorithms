#include "bits/stdc++.h"
#define int long long
using namespace std;

void solve(){
    int n;
    cin >> n;
    int arr[n + 1];
    int ans = 1;
    for(int i = 0; i < n; i++){
        int a;
        cin >> a;
        arr[a] = i;
    }
    int prev = 0;
    for(int i = 1; i < n + 1; i++){
        if(prev > arr[i]) ans++;
        prev = arr[i];
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

    