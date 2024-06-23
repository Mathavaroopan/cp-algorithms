#include<bits/stdc++.h>
using namespace std;
int main(){
    int t;
    cin>>t;
    while(t--){
        #define int long long
        int n, add, re;
        cin >> n >> re >> add;
        vector<int> arr;
        set<int> s;
        int ans = 0;
        int cur = 0;
        int side = 0;
        for(int i = 0; i < n; i++){
            int a;
            cin>>a;
            if(s.count(a) == 0){
                arr.push_back(a);
                s.insert(a);
            }else{
                ans += re;
                side += re;
            }
        }
        sort(arr.begin(), arr.end());
        int cost = 0;
        int m = arr.size();
        for(int i = 0; i < m; i++){
            if(arr[i] - cur - 1 > 0){
                cost = min(add*(arr[i] - cur - 1), re*(m - i));
                ans += cost;
                if(cost == re*(m - i)){
                    if(i == 0){
                        int count = 1;
                        for(int i = 1; i < n; i++){
                            if(arr[i] == arr[i-1] + 1){
                                count++;
                            }
                        }
                        ans -= cost;
                        ans += min((arr[i] - 1)*add + (m - count)*re, m*re + add);
                    }
                    break;
                }
            }
            cur = arr[i];
        } 
        ans = min(ans, m*re + add + side);
        cout << ans << endl;
    }
}