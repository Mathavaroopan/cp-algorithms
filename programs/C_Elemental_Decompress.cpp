#include<bits/stdc++.h>
using namespace std;
int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        int arr[n];
        int a[n], b[n];
        int mp[n + 1] = {0};
        map<int, int> mapp;
        set<int> s;
        for(int i = 0; i < n; i++){
            cin >> arr[i];
            if(mp[arr[i]] == 1) mapp[arr[i]] = i;
            mp[arr[i]]++;
        }
        bool status = false;
        for(auto i : mp){
            if(i > 2){
                std::cout << "NO" << endl;
                status = true;
                break;
            }
        }
        if(status) continue;
        
        for(int i = 1; i <= n; i++){
            if(mp[i] == 0) s.insert(i);
        }
        vector<bool> check(n + 1, false);
        for(int i = 0; i < n; i++){
            if(check[arr[i]] == true) continue;
            if(mp[arr[i]] == 1){
                a[i] = arr[i];
                b[i] = arr[i]; 
            }
            else if(mp[arr[i]] == 2){
                auto it = lower_bound(s.begin(), s.end(), arr[i]);
                if(it == s.begin()){
                    status = true;
                    break;
                }
                it--;
                if(arr[i] < *it){
                    status = true;
                    break;
                }
                a[i] = arr[i];
                b[i] = *it;
                a[mapp[arr[i]]] = *it;
                b[mapp[arr[i]]] = arr[i];
                s.erase(it);
                check[arr[i]] = true;
            }
        }
        if(status){
            std::cout << "NO" << endl;
            continue;
        }
        std::cout << "YES" << endl;
        for(int i = 0; i < n; i++) std::cout << a[i] << " ";
        std::cout << '\n';
        for(int i = 0; i < n; i++) std::cout << b[i] << " ";
        std::cout << '\n';
    }
}