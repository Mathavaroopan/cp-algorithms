#include<bits/stdc++.h>
using namespace std;
#define int long long

void solve(){
    int a, b;
    cin >> a >> b;
    vector<int> arr(18, 0);
    for(int i = a; i <= b; i++){
        int cur = 17;
        int temp = i;
        while(temp){
            if(temp & 1) arr[cur]++;
            temp >>= 1;
            cur--;
        }
    }
    cout << ((b - a) - *max_element(arr.begin(), arr.end())) + 1 << '\n';
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

    