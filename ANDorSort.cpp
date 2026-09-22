#include <bits/stdc++.h>
using namespace std;

int main() {
    int t;
    cin >> t;

    while (t--) {
        int n;
        cin >> n;

        string s;
        cin >> s;

        int ones = 0;

        for (char ch : s) {
            if (ch == '1') {
                ones++;
            }
        }

        // If first character is 1, it can never become 0.
        // So sorted string must be all 1s.
        if (s[0] == '1') {
            cout << n - ones << '\n';
            continue;
        }

        int leftones = 0;
        int ans = n;

        // Try every possible boundary:
        // 000...0 | 111...1
        for (int i = 0; i <= n; i++) {

            // Number of 0s on the right
            int rightzeroes = (n - i) - (ones - leftones);

            // 1s on left need to become 0
            // 0s on right need to become 1
            int operations = leftones + rightzeroes;

            ans = min(ans, operations);

            // Add s[i] to left side
            if (i < n && s[i] == '1') {
                leftones++;
            }
        }

        cout << ans << '\n';
    }

    return 0;
}