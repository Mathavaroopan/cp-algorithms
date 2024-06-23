#include<bits/stdc++.h>
using namespace std;
int main(){
    int t;
    cin>>t;
    while(t--){
        map<int, int> mp;
        int n;
        cin>>n;
        for(int i = 0; i < n; i++){
            int a;
            cin>>a;
            mp[a % 10]++;
        }
        vector<int> arr;
        for(auto it : mp){
            for(int i = 0; i < min(3, it.second); i++){
                arr.push_back(it.first);
            }
        }
        bool status = false;
        for(int i = 0; i < arr.size(); i++){
            for(int j = i + 1; j < arr.size(); j++){
                for(int k = j + 1; k < arr.size(); k++){
                    int temp = arr[i] + arr[j] + arr[k]; 
                    if(temp == 3 || temp == 13 || temp == 23){
                        status = true;
                        break;
                    }
                }
            }
        }
        if(status) cout << "YES" << endl;
        else cout << "NO" << endl;
    }
}