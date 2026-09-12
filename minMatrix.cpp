#include <bits/stdc++.h>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;
    while(t--){
        long long n, k;
        cin >> n >> k;
        if(k < n || k > 2*n - 1){
            cout << -1 << "\n";
            continue;
        }
        long long L = k - n + 1;
        long long s = n - L;
        vector<vector<long long>> A(n, vector<long long>(n, 0));

        A[s][s] = 1;
        long long val = 2;
        for(long long i = 0; i < s; i++){
            A[i][i] = val++;
        }
        for(long long j = s+1; j < n; j++){
            A[s][j] = val++;
        }
        for(long long i = s+1; i < n; i++){
            A[i][s] = val++;
        }
        for(long long i = 0; i < n; i++){
            for(long long j = 0; j < n; j++){
                if(A[i][j] == 0){
                    A[i][j] = val++;
                }
            }
        }

        for(long long i = 0; i < n; i++){
            for(long long j = 0; j < n; j++){
                cout << A[i][j];
                if(j + 1 < n) cout << ' ';
            }
            cout << "\n";
        }
    }
    return 0;
}