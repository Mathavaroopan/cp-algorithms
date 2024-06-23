/* Author: Mathavaroopan */
#include "bits/stdc++.h"
#define int long long
#define double long double
#define srt(arr) sort(arr.begin(), arr.end())
#define srtrev(arr) sort(arr.begin(), arr.end(), greater<int>())
#define reverse(arr) reverse(arr.begin(), arr.end())
#define all(arr) arr.begin(), arr.end()
#define input(arr) for(int& a : arr) cin >> a
#define print(arr) for(int i : arr) cout << i << " "
#define var(a) cout << #a << " = " << a << endl
#define min(arr) *min_element(arr.begin(), arr.end())
#define max(arr) *max_element(arr.begin(), arr.end())
#define sum(arr) accumulate(arr.begin(), arr.end(), 0)
#define endl '\n'
using namespace std;

const int mod = 1e9 + 7;
int inf = 1e18;
set<int> ans;

void solve(){
    int n;
    cin >> n;
    vector<int> arr(n);
    int s = 0;
    for(int& a : arr) cin >> a, s += a;
    ans.insert(0);
    for(int i = 0; i < n; i++){
        for(int x = s; x >= 0; x--){
            if(s >= x + arr[i] && ans.count(x)) ans.insert(x + arr[i]);
        }
    }
    ans.erase(0);
    cout << ans.size() << endl;
    print(ans); 
}
 
int32_t main()
{
 
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
 
    int T = 1;
    // cin >> T;
    while (T--) solve();
    return 0;
}
 