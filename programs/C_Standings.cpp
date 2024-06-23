#include<bits/stdc++.h>
using namespace std;
int main(){
    #define int long long
    #define double long double
    int n;
    cin >> n;
    map<double, vector<int>> mp;
    for(int i = 0; i < n; i++){
        double a, b;
        cin >> a >> b;
        mp[a/(a + b)].push_back(i + 1);
    }
    for(auto it = mp.rbegin(); it != mp.rend(); it++){
        for(auto i : it->second){
            cout << i << " ";
        }
    }
}