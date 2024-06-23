#include<bits/stdc++.h>

#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>

using namespace std;
using namespace __gnu_pbds;

typedef tree<int, null_type, less_equal<int>, rb_tree_tag, tree_order_statistics_node_update> pbds; 
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    #define int long long
    int t;
    cin>>t;
    while(t--){
        int n, l, r;
        cin >> n >> l >> r;
        vector<int> arr(n);
        for(int i = 0; i < n; i++){
            cin >> arr[i];
        }
        reverse(arr.begin(), arr.end());

        pbds ms;
        int ans = 0;
        for(int i = 0; i < n; i++){
            int templ = l;
            if(r <= arr[i]) continue;
            if(l <= arr[i]) templ = arr[i];
            ans += (ms.order_of_key(r - arr[i] + 1) - ms.order_of_key(templ - arr[i]));
            ms.insert(arr[i]);
        }
        cout << ans << endl;
    }
}