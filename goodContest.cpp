#include<iostream>
using namespace std;
int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        int a[3];
        cin>>a[0]>> a[1]>> a[2];
        int minVal= min(a[0],min(a[1],a[2]));
        int ans=n-minVal;
        cout<<ans<<endl;
}
return 0;
}
