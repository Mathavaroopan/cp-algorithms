#include<bits/stdc++.h>
using namespace std;

int main(){
    int n, k;
    cin >> n >> k;
    vector<int> arr(n);
    for(int i = 0; i < n; i++) cin >> arr[i];
    vector<int> prev(k + 1, 1e9), cur(k + 1, 1e9);
    for(int i = 0; i <= k; i++){
        if(i % arr[0] == 0) prev[i] = i/arr[0];
    }
    
    for(int i = 1; i < n; i++){
        for(int j = 1; j <= k; j++){
            int left = 1e9;
            if(j >= arr[i]) left = 1 + cur[j - arr[i]];
            int right = prev[j];
            cur[j] = min(left, right);
        }
        prev = cur;
    }
    if(prev[k] == 1e9) cout << -1 << endl;
    else cout << prev[k];
}