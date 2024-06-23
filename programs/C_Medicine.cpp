#include<bits/stdc++.h>
using namespace std;
int main(){
    #define int long long
    int n, k; 
    cin >> n >> k;
    int a[n], b[n], diff[n] = {0};
    for(int i = 0; i < n; i++){
        cin >> a[i];
        cin >> b[i];
    }
    for(int i = 0; i < n; i++){
        diff[0] += b[i];
        if(a[i] < n) diff[a[i]] -= b[i];
    }
    for(int i : diff) cout << i << " " ;
    cout << endl;
    int cur = 0;
    int ans = 0;
    for(int i = 0; i < n; i++){
        cur += diff[i];
        cout << cur << " ";
        if(cur <= k){
            ans = i + 1;
            break;
        }
    } 
    cout << endl;
    cout << ans << endl;
}