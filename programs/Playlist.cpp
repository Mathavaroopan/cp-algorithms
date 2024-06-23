#include "bits/stdc++.h"
#define int long long
using namespace std;


void solve(){
    int n;
    cin >> n;
    int arr[n];
    for(int i = 0; i < n; i++) cin >> arr[i];
    int i = 0, j = 0;
    int ans = 0;
    set<int> s;
    while(j < n){
        if(s.count(arr[j])){
            while(arr[i] != arr[j]){
                s.erase(arr[i]);
                i++;
            }
            s.erase(arr[i]);
            i++;
        }else{
            s.insert(arr[j]);
            ans = max(ans, j - i + 1);
            j++;
        }
    }    
    cout << ans << endl;
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

    