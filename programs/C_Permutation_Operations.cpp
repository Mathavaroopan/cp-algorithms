#include<bits/stdc++.h>
using namespace std;
int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        int index = 0;
        set<int> s;
        for(int i = 1; i <= n; i++) s.insert(i);
        int arr[n];
        cin >> arr[0];
        int ans[n + 1];
        ans[0] = 1;
        int sum[n + 1] = {0};
        for(int i = 1; i < n; i++){
            cin >> arr[i];
            if(arr[index] >= arr[i]){
                auto it = s.lower_bound(abs(arr[index] - arr[i]) + 1);
                if(it != s.end()){
                    arr[i] += *it;
                    sum[i + 1] = *it;
                    index = i;
                    s.erase(it);
                    ans[*it] = i + 1;
                }
            }else{
                index = i;
            }
        }

        int cur = sum[0];
        for(int i = 0; i < n; i++){
            arr[i] += cur;
            cur += sum[i];
        }
        
        sum[n + 1] = {0};
        for(int i = 1; i < n && !s.empty(); i++){
            while(arr[i - 1] >= arr[i] && !s.empty()){
                auto it = --s.end();
                sum[i + 1] += *it;
                arr[i] += *it;
                s.erase(it);
                ans[*it] = i + 1;
            }
        }
        for(int i : s){
            ans[i] = 1;
        }
        for(int i = 0; i < n; i++) cout << ans[i] << " ";
        cout << endl;
    }
}