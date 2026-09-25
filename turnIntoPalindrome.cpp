#include <bits/stdc++.h>
using namespace std;

int main() {
    int t;
    cin >> t;

    while (t--) {
        int coins = 0;

        int n;
        char c;
        cin >> n >> c;

        string s;
        cin >> s;

        for (int i = 0; i < n / 2; i++) {

            if (s[i] != s[n - i - 1]) {

                if (s[i] == c || s[n - i - 1] == c) {
                    coins++;
                }
                else {
                    coins += 2;
                }
            }
        }

        cout << coins << endl;
    }

    return 0;
}