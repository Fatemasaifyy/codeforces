#include <bits/stdc++.h>
using namespace std;

int main() {
    int t;
    cin >> t;

    while (t--) {
        int n;
        long long k;
        cin >> n >> k;

        vector<long long> a(n);

        for (int i = 0; i < n; i++) {
            cin >> a[i];
        }

        // c[i] = a[i] - i*k
        vector<long long> c(n);

        for (int i = 0; i < n; i++) {
            c[i] = a[i] - 1LL * i * k;
        }

        // Prefix sum of c
        vector<long long> pref(n + 1, 0);

        for (int i = 0; i < n; i++) {
            pref[i + 1] = pref[i] + c[i];
        }

        for (int i = 0; i < n; i++) {

            // First or last element remove karne par
            // array already good rahega
            if (i == 0 || i == n - 1) {
                cout << 0 << " ";
                continue;
            }

            long long d = c[i - 1] - k;

            // c is decreasing.
            // Find first position j where c[j] <= d.
            int lo = i + 1, hi = n - 1;
            int pos = n;

            while (lo <= hi) {
                int mid = (lo + hi) / 2;

                if (c[mid] <= d) {
                    pos = mid;
                    hi = mid - 1;
                } else {
                    lo = mid + 1;
                }
            }
            int l = i + 1;
            int r = pos - 1;

            if (l > r) {
                cout << 0 << " ";
            }
            else {
                long long cnt = r - l + 1;

                long long sum = pref[r + 1] - pref[l];

                long long ans = sum - cnt * d;

                cout << ans << " ";
            }
        }

        cout << '\n';
    }

    return 0;
}