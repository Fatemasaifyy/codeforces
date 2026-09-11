#include<bits/stdc++.h>
using namespace std;
int main(){
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        vector<int> a(n);
        for(int i = 0; i < n; i++)
            cin >> a[i];
        int cnt = 0;
        for(int i = 0; i < n; i++){
            if(a[i] == 0)
                cnt++;
        }
        if(cnt < 2){
            cout << -1 << endl;
        }
        else{
            cout<<a[0]+a[n-1]<<endl;
        }
    }
}