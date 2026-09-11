#include <bits/stdc++.h>
using namespace std;

int main() {

    int t;
    cin >> t;

    while (t--) {

        int n;
        string s;
        cin >> n >> s;

        const int INF = 1e9;

        // dp[v+3] = minimum cost when current prefix sum = v
        vector<int> dp(7, INF), ndp(7, INF);

        // First prefix sum
        for (int v = -3; v <= 3; v++) {

            bool ok = false;

            if (s[0] == '+' && v > 0)
                ok = true;

            if (s[0] == '-' && v < 0)
                ok = true;

            if (s[0] == '0' && v == 0)
                ok = true;

            if (ok && v != 0)
                dp[v + 3] = abs(v);
        }

        for (int i = 1; i < n; i++) {

            fill(ndp.begin(), ndp.end(), INF);

            for (int prev = -3; prev <= 3; prev++) {

                if (dp[prev + 3] == INF)
                    continue;

                for (int cur = -3; cur <= 3; cur++) {

                    bool ok = false;

                    if (s[i] == '+' && cur > 0)
                        ok = true;

                    if (s[i] == '-' && cur < 0)
                        ok = true;

                    if (s[i] == '0' && cur == 0)
                        ok = true;

                    if (!ok)
                        continue;

                    // a[i] = cur - prev
                    // a[i] cannot be zero
                    if (cur == prev)
                        continue;

                    int newCost = max(
                        dp[prev + 3],
                        abs(cur - prev)
                    );

                    ndp[cur + 3] = min(
                        ndp[cur + 3],
                        newCost
                    );
                }
            }

            dp = ndp;
        }

        int ans = *min_element(dp.begin(), dp.end());

        if (ans == INF)
            cout << -1 << '\n';
        else
            cout << ans << '\n';
    }

    return 0;
}