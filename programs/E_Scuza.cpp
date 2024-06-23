#include<bits/stdc++.h>
using namespace std;
int main(){
    int t;
    cin>>t;
    while(t--){
        long long n, k;
        cin>>n>>k;
        long long arr[n + 1] = {0};
        long long sum[n + 1] = {0};
        long long maxx = 0;
        for(int i = 1; i <= n; i++){
            long long a;
            cin>>a;
            maxx = max(maxx, a);
            arr[i] = maxx;
            sum[i] = a;
        }
        long long cur = sum[0];
        for(int i = 1; i <= n; i++){
            cur = sum[i - 1];
            sum[i] += cur;
        }
        for(int i = 0; i < k; i++){
            int target;
            cin>>target;
            int ans = upper_bound(arr, arr + n + 1, target) - arr - 1;
            cout << sum[ans] << " ";
        }
        cout << endl;
    }
}