#include<bits/stdc++.h>
using namespace std;
int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        int arr[n];
        for(int i = 0; i < n; i++) cin >> arr[i];
        if(n == 1){
            cout << 0 << endl;
            continue;
        }
        cout << n - 1 << endl;
        cout << 1 << " " << n << endl;
        if((arr[0] + arr[n - 1]) % 2 == 0) arr[0] = arr[n - 1];
        else arr[n - 1] = arr[0];
        for(int i = 1; i < n - 1; i++){
            if((arr[i] + arr[0]) % 2 == 1) cout << 1 << " " << i + 1 << endl;
            else cout << i + 1 << " " << n << endl;
        }
    }
}