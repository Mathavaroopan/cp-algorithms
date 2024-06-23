#include<bits/stdc++.h>
using namespace std;
int main(){
    int t;
    cin >> t;
    while(t--){
        #define int long long
        int n;
        cin >> n;
        int arr[n], brr[n];
        int mina = LLONG_MAX, minb = LLONG_MAX;
        for(int i = 0; i < n; i++){
            cin >> arr[i];
            mina = min(mina, arr[i]);
        }
        for(int i = 0; i < n; i++){
            cin >> brr[i];
            minb = min(minb, brr[i]);
        }
        int ans = 0;
        for(int i = 0; i < n; i++){
            int diffa = abs(arr[i] - mina);
            int diffb = abs(brr[i] - minb);
            ans += max(diffa, diffb);
        }
        cout << ans << endl;
    }
}