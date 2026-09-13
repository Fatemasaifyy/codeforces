#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll MOD = 998244353LL;

const int MAXN = 200005;
ll fact[MAXN], inv_[MAXN];

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    fact[0] = 1;
    for (int i = 1; i < MAXN; i++) fact[i] = fact[i-1] * i % MOD;

    inv_[1] = 1;
    for (int i = 2; i < MAXN; i++) {
        inv_[i] = (MOD - (MOD / i) * inv_[MOD % i] % MOD) % MOD;
    }

    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<ll> a(n);
        for (auto &x : a) cin >> x;

        sort(a.begin(), a.end(), greater<ll>()); // c_1 > c_2 > ... > c_n

        vector<ll> S(n+1, 0);
        for (int k = 1; k <= n; k++) {
            S[k] = (S[k-1] + (a[k-1] % MOD)) % MOD;
        }

        ll sumTerm = 0;
        for (int k = 1; k <= n-1; k++) {
            sumTerm = (sumTerm + S[k] * inv_[k]) % MOD;
        }

        ll sumAll = S[n];
        ll c1 = a[0] % MOD;
        ll othersSum = (sumAll - c1 + MOD) % MOD;

        ll innerSum = (sumTerm - othersSum + MOD) % MOD;

        ll ans = fact[n-1] * innerSum % MOD;

        cout << ans << '\n';
    }
}