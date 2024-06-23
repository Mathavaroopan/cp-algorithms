#include "bits/stdc++.h"
#define int long long
using namespace std;

int n;
const int temp = 4e18 + 7;
vector<int> arr(1e6);
int fun(int i, int bal, int neg){
    if(bal == 0) return 1;
    if(i < 0) return temp;
    int left = fun(i - 1, bal, neg);
    int right = fun(i - 1, bal - 1, (arr[i] < 0) ? (neg + 1) : neg);
    if((left == temp || left == -temp) && (right == temp || right == -temp)) return (neg & 1) ? temp : -temp;
    else if(left == temp || left == -temp) return right;
    else if(right == temp || right == -temp) return left;
    return max(left, arr[i] * right); 
}

void solve(){
    cin >> n;
    for(int i = 0; i < n; i++) cin >> arr[i];
    cout << fun(n - 1, 5, 0) << endl;
}

int32_t main()
{
 
 ios_base::sync_with_stdio(false);
 cin.tie(NULL);

    int T = 1;
    cin >> T;
    while (T--)
    {
        solve();
    }
    return 0;
}

    