#include<bits/stdc++.h>
using namespace std;
int main(){
    string s;
    cin >> s;
    int n = s.length();
    string t="";
    for(int i=0; i<n; i++){
        if(s[i]!='+'){
            t+=s[i];
        }
    }
    sort(t.begin(), t.end());
        for(int i=0; i<t.length(); i++){
            cout<<t[i];
            if(i!=t.length()-1)cout<<"+";
        }
}
    
