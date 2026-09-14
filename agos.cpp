#include <bits/stdc++.h>
using namespace std;

int main(){
    int t;
    scanf("%d", &t);
    while(t--){
        long long n;
        scanf("%lld", &n);
        string s(n, '0');
        if(n==1){
            s[0]='1';
        } else if(n==2){
            s[0]='1'; s[1]='1';
        } else {
            long long n1 = n+1;
            long long q = n1/3;
            long long r = n1%3;
            if(r==0 && (q%2==1)){
                long long p1=q, p2=q+2, p3=2*q+2;
                s[p1-1]='1';
                s[p2-1]='1';
                s[p3-1]='1';
            } else {
                long long sz[3];
                int idx=0;
                for(long long i=0;i<r;i++) sz[idx++]=q+1;
                for(long long i=0;i<3-r;i++) sz[idx++]=q;
                int bpos=-1;
                for(int i=0;i<3;i++) if(sz[i]%2==0){ bpos=i; break; }
                long long B = sz[bpos];
                long long A=-1, C=-1;
                bool gotA=false;
                for(int i=0;i<3;i++){
                    if(i==bpos) continue;
                    if(!gotA){ A=sz[i]; gotA=true; }
                    else C=sz[i];
                }
                long long p1=A, p2=A+B;
                s[p1-1]='1';
                s[p2-1]='1';
            }
        }
        printf("%s\n", s.c_str());
    }
}