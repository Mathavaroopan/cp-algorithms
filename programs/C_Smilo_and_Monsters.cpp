#include<bits/stdc++.h>
using namespace std;
int main(){
    #define int long long
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        int arr[n];
        int i = 0, j = n - 1;
        for(int i = 0; i < n; i++) cin >> arr[i];
        sort(arr, arr + n);
        int cur = 0;
        int ans = 0;
        while(i < j){
            if(cur + arr[i] > arr[j]){
                arr[i] -= (arr[j] - cur);
                ans += (arr[j] - cur + 1);
                j--;
                cur = 0;
            }else{
                cur += arr[i];
                ans += arr[i];
                i++;
            }
        }
       
        arr[i] += cur;
        ans -= cur;
        if(arr[i] == 0) ans = ans;
        else if(arr[i] == 1) ans++;
        else if(arr[i] & 1) ans += (arr[i]/2) + 2;
        else ans += (arr[i]/2) + 1;
        cout << ans << endl;
    }
}