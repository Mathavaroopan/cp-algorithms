/* Author: Mathavaroopan */
#include "bits/stdc++.h"
#define int long long
#define srt(arr) sort(arr.begin(), arr.end())
using namespace std;

void solve(){
    string s;
    cin >> s;
    char first = s[0];
    for(int i = 1; i < (int) s.size(); i++){
        if(s[i] != first){
            cout << "YES" << endl;
            cout << s[i];
            for(int j = 1; j < (int) s.size(); j++){
                if(i != j) cout << s[j];
                else cout << first;
            }
            cout << endl;
            return;
        }
    }    
    cout << "NO" << endl;
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
 