#include<bits/stdc++.h>
using namespace std;
int main(){
    int t;
    cin>>t;
    map<string, int> mp;
    while(t--){
        string s;
        cin>>s;
        if(mp[s] == 0){
            cout << "OK" << endl;
            mp[s]++;
        }else{
            cout << (s + to_string(mp[s])) << endl;
            mp[s]++;
        }
    }
}