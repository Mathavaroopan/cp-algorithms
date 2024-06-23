#include "bits/stdc++.h"
#define int long long
#define uint unsigned long long
using namespace std;

int n, k;
vector<int> arr;

bool check(int mid){
    int sum = 0;
    int cnt = 1;
    for(int& a : arr){
        if(sum + a <= mid) sum += a;
        else{
            sum = a;
            cnt++;
        }
    }
    return cnt <= k;
}

void solve(){
    cin >> n >> k;
    arr.resize(n);
    for(int& a : arr) cin >> a;
    int low = *max_element(arr.begin(), arr.end());
    int high = accumulate(arr.begin(), arr.end(), 0);
    while(low <= high){
        int mid = (low + high)/2;
        if(check(mid)) high = mid - 1;
        else low = mid + 1;
    }
    cout << low << endl;
}

int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int T = 1;
    while (T--) solve();
    return 0;
}

    