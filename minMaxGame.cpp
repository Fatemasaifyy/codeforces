#include <bits/stdc++.h>
using namespace std;

int main(){
    int t;
    scanf("%d", &t);
    while(t--){
        int n;
        scanf("%d", &n);
        int ones = 0;
        for(int i = 0; i < n; i++){
            int x;
            scanf("%d", &x);
            ones += x;
        }
        if(2 * ones >= n)
            printf("Bessie\n");
        else
            printf("Elsie\n");
    }
    return 0;
}