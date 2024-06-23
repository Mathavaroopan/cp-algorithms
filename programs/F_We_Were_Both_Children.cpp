#include<bits/stdc++.h>
using namespace std;
int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        map<int, int> mp;
        map<int, int> count;
        for(int i = 0; i < n; i++){
            int a;
            cin>>a;
            if(a <= n) count[a]++;
        }
        for(auto it : count){
            int cur = it.second;
            for(int i = it.first; i <= n; i += it.first){
                mp[i] += cur;
            }
        }
        int ans = 0;
        for(auto it : mp){
            ans = max(ans, it.second);
        }
        cout << ans << endl;
    }
}