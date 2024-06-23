#include<bits/stdc++.h>
using namespace std;
int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        vector<long long> arr;
        long long pos = 0, neg = 0, zero = 0;
        for(int i = 0; i < n; i++){
            long long a;
            cin>>a;
            if((a == 0 && zero < 3) || a != 0) arr.push_back(a);
            if(a > 0) pos++;
            else if(a < 0) neg++;
            else zero++;
        }
        if((pos > 2 || neg > 2)) cout << "NO" << endl;
        else{
            bool status = false;
            n = arr.size();
            sort(arr.begin(), arr.end());
            for(int i = 0; i < n; i++){
                for(int j = i + 1; j < n; j++){
                    for(int k = j + 1; k < n; k++){
                        if(binary_search(arr.begin(), arr.end(), arr[i] + arr[j] + arr[k]) == false){
                            status = true;
                            goto end_loop;
                        }
                    }
                }
            }
            cout << "YES" << endl;
            end_loop:
            if(status) cout << "NO" << endl;

        }
    }
}