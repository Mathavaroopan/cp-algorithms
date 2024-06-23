#include<bits/stdc++.h>
using namespace std;
int main(){
    int t;
    cin >> t;
    while(t--){
        int n, m;
        cin>>n>>m;
        if(n == 1 || m == 1) cout << "YES" << endl;
        else{
            if(n <= m) cout << "NO" << endl;
            else{
                int mini = -1;
                for(int i = 2; i*i <= n; i++){
                    if(n % i == 0){
                        mini = i;
                        break;
                    }
                }
                if(mini == -1) cout << "YES" << endl;
                else if(m >= mini) cout << "NO" << endl;
                else cout << "YES" << endl;
            }
        }
    }
}