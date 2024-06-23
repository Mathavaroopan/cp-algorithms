#include<bits/stdc++.h>
using namespace std;
int main(){
    int t;
    cin >> t;
    while(t--){
        int a, b;
        cin >> a >> b;
        string s;
        cin >> s;
        int i = 0, j = s.size() - 1;
        while(i < s.size() && s[i] != '1'){
            i++;
        }
        while(j >= 0 && s[j] != '1'){
            j--;
        }
        int count = 0;
        int ans = 0;
        if(j < i){
            cout << 0 << endl;
            continue;
        }
        vector<int> zeros;
        while(i <= j){
            if(s[i] == '1'){
                if(count == 0){
                    i++;
                    continue;
                }
                zeros.push_back(count);
                count = 0;
            }else{
                count++;
            }
            i++;
        }
        ans = a;
        for(int i : zeros){
            ans += min(a, i*b);
        }
        cout << ans << endl;
    }
}