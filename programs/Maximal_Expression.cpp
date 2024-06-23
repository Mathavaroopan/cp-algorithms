#include<bits/stdc++.h>
using namespace std;

int main(){
    int t;
    cin>>t;
    while(t--){
        long long n, k;
        cin>>n>>k;
        if(n <= k){
            long long a = n / 2, b = (n + 1)/2;
            cout << a << " " << b << endl;
            while((a % k == 0 || b % k == 0) && a > 0){
                
                a--, b++;
                if(a <= 0) break;
            }
            cout << a << endl;
        }
        else if((n & 1) && k == 2) cout << 0 << endl;
        else{
            long long a = k - 1, b = n - (k - 1);
            while((a % k == 0 || b % k == 0) && a > 0){
                a--, b++;
                if(a <= 0) break;
            }
            cout << a << endl;
        }

    }
}