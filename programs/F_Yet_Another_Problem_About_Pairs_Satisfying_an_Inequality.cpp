#include<bits/stdc++.h>
using namespace std;

int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        long long ans = 0;
        vector<pair<long long, long long>> arr;
        for(int i = 0; i < n; i++){
            int a;
            cin>>a;
            if(a < i + 1) arr.push_back({a, i + 1});
        }
        if(arr.size() == 0){
            cout << 0 << endl;
            continue;
        }
        sort(arr.begin(), arr.end());

        for(int i = 0; i < arr.size() - 1; i++){
            int index = upper_bound(arr.begin(), arr.end(), make_pair(arr[i].second, 0), [](const auto& a, const auto& b) {return a.first < b.first;}) - arr.begin();
            ans += arr.size() - index;
        }
        cout << ans << endl;
    }
}