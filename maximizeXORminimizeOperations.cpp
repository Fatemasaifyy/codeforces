#include<bits/stdc++.h>
using namespace std;

int main(){

    int t;
    cin >> t;

    while(t--){

        long long x, y;
        cin >> x >> y;

        long long s = x + y;
        long long best = 0;

        for(int i = 29; i >= 0; i--){

            if((s & (1LL << i)) && best + (1LL << i) <= x){
                best += (1LL << i);
            }

        }

        cout << s << " " << x - best << endl;
    }

    return 0;
}