#include<bits/stdc++.h>
using namespace std;
int main(){
    long long n, k;
    cin>>n>>k;
    if(k == 1) cout << n << endl;
    else{
        long long ans = 1;
        while(ans <= n){
            ans <<= 1;
        }
        cout << ans - 1 << endl;
    }
}