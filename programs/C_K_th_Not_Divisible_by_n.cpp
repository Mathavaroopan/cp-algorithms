#include "bits/stdc++.h"
#define int long long
using namespace std;


void solve(){
    int n, k;
    cin >> n >> k;
    int low = 1, high = 1e10;
    while(low <= high){
        int mid = (low + high)/2;
        if(mid - mid/n == k){
            if(mid % n == 0) mid--;
            cout << mid << endl;
            return;
        }else if(mid - mid/n > k) high = mid - 1;
        else low = mid + 1;
    }
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

    