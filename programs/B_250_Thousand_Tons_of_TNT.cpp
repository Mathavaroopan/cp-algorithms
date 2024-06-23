#include<bits/stdc++.h>
using namespace std;
int main(){
    int t;
    cin >> t;
    while(t--){
        #define int long long
        int n;
        cin >> n;
        int arr[n];
        for(int i = 0; i < n; i++) cin >> arr[i];
        int prefix[n + 1] = {0};
        for(int i = 0; i < n; i++){
            prefix[i + 1] = prefix[i] + arr[i];
        }
        int ans = 0;
        for(int k = 1; k <= n / 2; k++){
            if(n % k == 0){
                int mn = LLONG_MAX, mx = 0;
                for(int i = 0; i < n; i += k){
                    mn = min(mn, prefix[i + k] - prefix[i]);
                    mx = max(mx, prefix[i + k] - prefix[i]);
                }
                ans = max(mx - mn, ans);
            }
        }
        cout << ans << endl;
    }
}

