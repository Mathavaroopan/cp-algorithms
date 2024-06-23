#include<bits/stdc++.h>
using namespace std;
int main(){
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        int a;
        cin >> a;
        int mini = INT_MAX;
        for(int i = 1; i < n; i++){
            int b;
            cin >> b;
            mini = min(mini, b);
        }
        if(a <= mini) cout << "Bob" << endl;
        else cout << "Alice" << endl;
    }
}