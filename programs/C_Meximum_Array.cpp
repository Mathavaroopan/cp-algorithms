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
#define sum(arr) accumulate(arr.begin(), arr.end(), 0)
#define endl '\n'
using namespace std;

const int mod = 1e9 + 7;
int inf = 1e18;

void solve(){   
    int n; cin >> n;
    vector<int> arr(n);
    map<int, int> s;
    for(int i = 0; i < n; i++){
        cin >> arr[i];
        s[arr[i]]++;
    }
    int i = 0, mex = 0;
    vector<int> ans;
    while(i < n){
        set<int> cur;
        for(int j = 0; j <= n; j++){
            if(s[j] == 0){
                mex = j;
                break;
            }
        }
        ans.push_back(mex);
        if(mex == 0){
            s[arr[i]]--;
            i++;
        }else{
            while(cur.size() != mex && i < n){
                if(arr[i] < mex) cur.insert(arr[i]);
                s[arr[i]]--;
                i++;
            }
        }
    }
    cout << ans.size() << endl;
    print(ans);
    cout << endl;
}
 
int32_t main()
{
 
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
 
    int T = 1;
    cin >> T;
    while (T--) solve();
    return 0;
}
 