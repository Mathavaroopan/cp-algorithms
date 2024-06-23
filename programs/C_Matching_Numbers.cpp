#include<bits/stdc++.h>
using namespace std;
int main(){
    int t;
    cin >> t;
    while(t--){
        int n;
        cin>>n;
        if(n % 2 == 0) cout << "No" << endl;
        else{
            int y = 2*n;
            cout << "Yes" << endl;
            for(int i = 1; i <= n; i += 2){
                cout << i << " " << y << endl;
                y--;
            }
            for(int i = 2; i <= n; i += 2){
                cout << i << " " << y << endl;
                y--;
            }
        } 
    }
}