#include<bits/stdc++.h>
using namespace std;

int main(){
    int n, a, b, c;
    cin >> n >> a >> b >> c;
    int ans = 0;
    for(int i = 0; i < 4001; i++){
        for(int j = 0; j < 4001; j++){
            if((n - a*i - b*j) < 0) break;
            else if((n - a*i - b*j) % c == 0){
                ans = max(ans, i + j + ((n - a*i - b*j)/c));
            }
        }
        if(n - a*i < 0) break;
    }
    cout << ans << endl;
}