#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        vector<ll> a(n);
        for (auto &x : a) cin >> x;

        int capacity = m - 1;
        priority_queue<ll> heap;
        ll runningSum = 0;
        ll best = LLONG_MIN;

        for (int p = 0; p < n; p++) {
            if (p >= capacity) {
                ll candidate = (ll)m * a[p] - runningSum;
                best = max(best, candidate);
            }
            if (capacity > 0) {
                if ((int)heap.size() < capacity) {
                    heap.push(a[p]);
                    runningSum += a[p];
                } else if (!heap.empty() && a[p] < heap.top()) {
                    runningSum += a[p] - heap.top();
                    heap.pop();
                    heap.push(a[p]);
                }
            }
        }

        cout << best << '\n';
    }
}