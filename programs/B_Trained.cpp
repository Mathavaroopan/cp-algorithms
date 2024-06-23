#include<bits/stdc++.h>
using namespace std;
int main(){
    int n;
    cin >> n;
    vector<int> arr(n), vis(n, 0);
    for(int i = 0; i < n; i++){
        cin >> arr[i];
        arr[i]--;
    }
    int ans = 0;
    int cur = 0;
    while(true){
        if(cur == 1){
            break;
        }
        if(vis[cur]){
            cout << -1 << endl;
            return 0;
        }
        ans++;
        vis[cur] = 1;
        cur = arr[cur];
    }
    cout << ans << endl;
}