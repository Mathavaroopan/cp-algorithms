#include<bits/stdc++.h>
using namespace std;

int help(int maxx){
    int ans = 0;
    while(maxx){
        ans++;
        maxx >>= 1;
    }
    return ans;
}
int main(){
    int t;
    cin>>t;
    while(t--){
        string s;
        cin>>s;
        set<char> st;
        for(char i : s) st.insert(i);
        int ans = 0;
        int mini = INT_MAX;
        for(char a : st){
            int maxx = 0, cur = 0;
            for(int i = 0; i < s.size(); i++){
                if(s[i] == a){
                    maxx = max(maxx, cur);
                    cur = 0;
                }else{
                    cur++;
                }
            }
            maxx = max(maxx, cur);
            mini = min(maxx, mini);
        }
        ans = help(mini);
        cout << ans << endl;
    }
}