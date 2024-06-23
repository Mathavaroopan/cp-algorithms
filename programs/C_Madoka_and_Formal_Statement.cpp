#include<bits/stdc++.h>
using namespace std;
int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin >> n;
        int arr[n + 1], brr[n + 1];
        for(int i = 0; i < n; i++){
            cin >> arr[i];
        }
        for(int i = 0; i < n; i++){
            cin >> brr[i];
        }
        arr[n] = arr[0];
        brr[n] = brr[0];
        int i = 0;
        for(i = 0; i < n; i++){
            if(arr[i] > brr[i]) break;
            if(arr[i] == brr[i]) continue;
            if(brr[i] > brr[i + 1] + 1) break;
        }
        if(i == n) cout << "YES" << endl;
        else cout << "NO" << endl;
    }
}