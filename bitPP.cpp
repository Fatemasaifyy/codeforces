#include<iostream>
using namespace std;
int main(){
    int n, cnt=0;
    string s;
    cin>>n;
    while(n--){
        cin>>s;
        if(s.find("++")!=string::npos)
            cnt++;
        else cnt--;
    }
    
    cout<<cnt<<endl;
    return 0;
}