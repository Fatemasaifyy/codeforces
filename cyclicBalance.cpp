#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, q;
    cin >> n >> q;

    string s;
    cin >> s;

    vector<int> pref0(n + 1, 0);
    vector<int> pref01(n + 1, 0);
    vector<int> pref10(n + 1, 0);

    for (int i = 1; i <= n; i++) {
        pref0[i] = pref0[i - 1] + (s[i - 1] == '0');

        pref01[i] = pref01[i - 1];
        pref10[i] = pref10[i - 1];

        if (i >= 2) {
            if (s[i - 2] == '0' && s[i - 1] == '1')
                pref01[i]++;

            if (s[i - 2] == '1' && s[i - 1] == '0')
                pref10[i]++;
        }
    }

    while (q--) {
        int l, r;
        cin >> l >> r;

        int len = r - l + 1;

        int zeros = pref0[r] - pref0[l - 1];
        int ones = len - zeros;

        // Internal pairs only
        int cnt01 = pref01[r] - pref01[l];
        int cnt10 = pref10[r] - pref10[l];

        int k = max({
            (zeros + 1) / 2,
            (ones + 1) / 2,
            cnt01,
            cnt10
        });

        if (4 * k == len) {

            int cyclic01 = cnt01;
            int cyclic10 = cnt10;

            // Closing pair: s[r] -> s[l]
            if (s[r - 1] == '0' && s[l] - 1 == '1')
                cyclic01++;

            if (s[r - 1] == '1' && s[l - 1] == '0')
                cyclic10++;

            if (cyclic01 != k || cyclic10 != k)
                k++;
        }

        cout << 4 * k - len << '\n';
    }

    return 0;
}