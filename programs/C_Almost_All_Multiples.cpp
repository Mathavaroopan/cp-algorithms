/* Author: Mathavaroopan */
#include "bits/stdc++.h"
#define int long long
#define srt(arr) sort(arr.begin(), arr.end())
using namespace std;

void solve(){
    int n, x;
    cin >> n >> x;
    vector<int> arr(n + 1, 0);
    if(n % x != 0){
        cout << -1 << endl;
        return;
    }
    arr[1] = x, arr[n] = 1;
    int temp = n;
    for(int i = x; i < n;){
        if(temp % i == 0){
            int a = 2*i;
            int guy = 0;
            while(a < n){
                if(temp % a == 0){
                    guy = a;
                    break;
                }
                a += i;
            }
            if(!guy){
                arr[i] = temp;
                break;
            }else{
                arr[i] = guy;
                i = a;
            }
        }else i++;
    }
    for(int i = 1; i <= n; i++){
        if(!arr[i]) cout << i << " ";
        else cout << arr[i] << " ";
    }
    cout << endl;
}
 
int32_t main()
{
 
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
 
    int T = 1;
    cin >> T;
    while (T--) solve();
    return 0;
}
 