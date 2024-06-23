#include<bits/stdc++.h>
using namespace std;
int main(){
    int t;
    cin >> t;
    while(t--){
        long long n, zz;
        cin>>n>>zz;
        long long anss = 0;
        for(int i = 0; i < n; i++){
            long long a;
            cin >> a;
            long long ans = a;
            long long temp = ans;
            long long tempz = zz;
            long long z = zz;
            for(int i = 0; i < 20000 && z != 0; i++){
                temp = ans;
                ans |= z;
                tempz = z;
                z &= temp;
            }
            anss = max(ans, anss);
        }
        
        cout << anss << endl;
    }
}