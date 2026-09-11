#include<iostream>
using namespace std;
int main(){
    string s;
    cin>>s;
    bool seen[26]={false};
    for(int i=0;i<s.length();i++){
        seen[s[i]-'a']=true;
    }
    int cnt=0;
    for(int i=0;i<26;i++){
        if (seen[i])cnt++;
    }
    if (cnt%2==0)cout<<"CHAT WITH HER!";
    else cout<<"IGNORE HIM!";
    cout<<endl;
    
}