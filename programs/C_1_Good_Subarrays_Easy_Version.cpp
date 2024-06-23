#include<bits/stdc++.h>
using namespace std;
int main(){
    #define int long long
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        int prev;
        cin>>prev;
        int prevsum = 1;
        int ans = 1;
        for(int i = 1; i < n; i++){
            int a;
            cin>>a;
            prevsum = min(prevsum + 1, a);
            ans += prevsum;
        }
        cout << ans << endl;
    }
}