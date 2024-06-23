#include "bits/stdc++.h"
#define int long long
using namespace std;

void solve(){
    int n, sum;
    cin >> n >> sum;
    vector<pair<int, int>> arr(n);
    for(int i = 0; i < n; i++){
        cin >> arr[i].first;
        arr[i].second = i + 1;
    }   
    sort(arr.begin(), arr.end());
    for(int i = 0; i < n; i++){
        int j = i + 1, k = n - 1;
        while(j < k){
            if(arr[i].first + arr[j].first + arr[k].first == sum){
                cout << arr[i].second << " " << arr[j].second << " " << arr[k].second << endl;
                return;
            }else if(arr[i].first + arr[j].first + arr[k].first < sum){
                j++;
            }else k--;
        }
    }
    cout << "IMPOSSIBLE" << endl;
}

int32_t main()
{
 
 ios_base::sync_with_stdio(false);
 cin.tie(NULL);

    int T = 1;
    while (T--)
    {
        solve();
    }
    return 0;
}

    