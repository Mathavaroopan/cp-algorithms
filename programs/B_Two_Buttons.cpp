#include<bits/stdc++.h>
using namespace std;
int main(){
    #define int long long
    int n, m;
    cin >> n >> m;
    if(n >= m) cout << n - m << endl;
    else{
        int ans1 = 0, ans2 = 0;
        int a = n, b = m;
        while(a < b){
            a <<= 1;
            ans1++;
        }
        int ans = ans1 + (a - b);
        a = n;
        while(b > a){
            if(b & 1){
                b++;
                ans2++;
            }
            b >>= 1;
            ans2++;
        }
        ans = min(ans, ans2 + a - b);
        cout << ans << endl;
    }
}