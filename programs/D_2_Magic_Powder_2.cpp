#include "bits/stdc++.h"
#define int long long
#define uint unsigned long long
using namespace std;

int n, k;
bool check(int mid, vector<int>& arr, vector<int>& have){
    int need = 0;
    for(int i = 0; i < n; i++){
        if(have[i]/arr[i] < mid){
            need += arr[i]*mid - have[i];
        }
    }
    return need <= k;
}   

void solve(){
    cin >> n >> k;
    vector<int> arr(n), have(n);
    for(int& a : arr) cin >> a;
    for(int& a : have) cin >> a;
    int low = 0, high = 2e9 + 1;
    int ans = 0;
    while(low <= high){
        int mid = (low + high)/2;
        if(check(mid, arr, have)){
            ans = mid;
            low = mid + 1;
        }else high = mid - 1;
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

    