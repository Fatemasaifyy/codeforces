#include<bits/stdc++.h>
using namespace std;
int main(){
    int t;
    cin >> t;
    while(t--){
        long long x,y,k;
        long long sol=0;
        cin >> x >> y >> k;
        long long d=y-x;
        long long cnt=min(k, max(0LL, d-x+1));
        for(long long i=0; i<cnt; i++){
            sol+=d%(x+i);
        }
        sol+=(k-cnt)*d;
        cout<<sol<<endl;
    }
    return 0;
}