#include<bits/stdc++.h>
using namespace std;
int main(){
    int t;
    cin>>t;
    while(t--){
     int n;
     cin>>n;
     vector<int> a(n);
     for(int i=0; i<n; i++){
     cin>>a[i];
     }
     int odd=0, even1=0, even2=0;
     for(int i=0; i<n; i++){
        if(a[i]%2!=0){
            odd++;
        }
        else if((a[i]/2)%2==0) even1++;
        else even2++;
     }
     cout<< max({odd, even1, even2})<<endl;
    }
}
