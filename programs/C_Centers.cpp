#include<bits/stdc++.h>
using namespace std;
int main(){
    #define int long long
    #define double long double
    int n;
    cin >> n;
    map<int, vector<int>> mp;

    for(int i = 0; i < 3*n; i++){
        int a;
        cin >> a;
        mp[a].push_back(i + 1);    
    }

    map<int, int> ans;
    for(auto it : mp){
        ans[it.second[1]] = it.first;
    }
    for(auto it : ans){
        cout << it.second << " ";
    }
    
}