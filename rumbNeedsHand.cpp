#include <bits/stdc++.h> 
using namespace std; 
int main() { 
    ios::sync_with_stdio(false); 
    cin.tie(nullptr); 
 
    int t; 
    cin >> t; 
 
    while (t--) { 
        int n; 
        cin>>n; 
        vector<int> a(n); 
        for(int i=0;i<n;i++){ 
            cin>>a[i]; 
        } 
        vector<int> pos; 
        for(int i=0;i<n;i++){ 
                if(a[i]!=i+1){ 
                    pos.push_back(i); 
                } 
        } 
        bool ok=true; 
        for(int i=0;i<(int)pos.size();i++){ 
            if(a[pos[i]] !=pos[pos.size() - 1 - i] + 1){ 
                ok=false; 
                break; 
            } 
        } 
        cout<<(ok?"YES":"NO")<<"\n"; 
    } 
    return 0; 
}