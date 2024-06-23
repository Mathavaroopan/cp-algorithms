/* Author: Mathavaroopan */
#include "bits/stdc++.h"
#define int long long
#define srt(arr) sort(arr.begin(), arr.end())
using namespace std;

void solve(){
    string s;
    cin >> s;
    int l = 0, r = 0, n = s.size();
    int ans = 0;
    int start = -1, end = -1;
    while(r < n){
        while(r < n && s[r] == '1') r++;
        if(r < n && s[r] == '0'){
            l = r;
            while(r < n && s[r] == '0'){
                ans = max(ans, r - l + 1);
                r++;
            }
            while(r < n && s[r] == '1'){
                if(ans < r - l + 1){
                    ans = r - l + 1;
                    start = l;
                    end = r;
                }
                r++;
            }
        }
    }
    if(end != -1){
        int i = 0, more = 0;
        while(i < start){
            int cnt = 0;
            while(i < start && s[i] == '0'){
                i++;
                if(cnt == 0) cnt++;
            }
            int temp = cnt;
            while(i < start && s[i] == '1'){
                i++;
                if(cnt == temp) cnt++;
            }
            more += cnt;
        }
        i = end + 1;
        while(i < n){
            int cnt = 0;
            while(i < n && s[i] == '0'){
                i++;
                if(cnt == 0) cnt++;
            }
            int temp = cnt;
            while(i < n && s[i] == '1'){
                i++;
                if(cnt == temp) cnt++;
            }
            more += cnt;
        }
        cout << more + 1 << endl;
    }else{
        int i = 0, more = 0;
        while(i < n){
            int cnt = 0;
            while(i < n && s[i] == '0'){
                i++;
                if(cnt == 0) cnt++;
            }
            int temp = cnt;
            while(i < n && s[i] == '1'){
                i++;
                if(cnt == temp) cnt++;
            }
            more += cnt;
        }
        cout << more << endl;
    }
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
 