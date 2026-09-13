#include <bits/stdc++.h>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<int> a(n);
        for (auto &x : a) cin >> x;

        vector<int> diff(n + 2, 0);
        for (int i = 0; i < n; i++) {
            long long k = i + 1;
            long long ak = a[i];
            long long L = ak * k;
            if (L > n - 1) continue;
            long long R = min((long long)(n - 1), L + k - 1);
            diff[L] += 1;
            diff[R + 1] -= 1;
        }

        vector<int> B;
        B.reserve(n);
        int cur = 0;
        for (int y = 0; y < n; y++) {
            cur += diff[y];
            if (cur == 0) B.push_back(y);
        }

        cout << B.size() << '\n';
        for (size_t i = 0; i < B.size(); i++) {
            cout << B[i] << " \n"[i + 1 == B.size()];
        }
        if (B.empty()) cout << '\n';
    }
}