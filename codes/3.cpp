#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;

    while (t--) {
        int n;
        cin >> n;

        vector<long long> a(n);
        for (int i = 0; i < n; i++) {
            cin >> a[i];
        }

        map<long long, int> freq;
        for (auto x : a) freq[x]++;

        long long even_sum = 0;
        int even_sticks = 0;
        vector<long long> safe_adds, high_adds;
        long long max_always = 0;
        for (auto& p : freq) {
            long long l = p.first;
            int cnt = p.second;
            even_sum += l * (cnt / 2 * 2LL);
            even_sticks += cnt / 2 * 2;
            if (cnt >= 2) max_always = max(max_always, l);
            if (cnt % 2 == 1) {
                if (l > max_always) high_adds.push_back(l);
                else safe_adds.push_back(l);
            }
        }

        sort(safe_adds.rbegin(), safe_adds.rend());
        sort(high_adds.rbegin(), high_adds.rend());

        long long maxPerimeter = 0;

        // add 0
        if (even_sticks >= 3 && even_sum > 2LL * max_always) {
            maxPerimeter = even_sum;
        }

        // add 1
        long long best_add1 = 0;
        if (!safe_adds.empty()) {
            long long addl = safe_adds[0];
            long long S = even_sum + addl;
            long long M = max_always;
            if (even_sticks + 1 >= 3 && S > 2LL * M) {
                best_add1 = max(best_add1, addl);
            }
        }
        if (!high_adds.empty()) {
            for (auto h : high_adds) {
                if (h < even_sum) {
                    long long S = even_sum + h;
                    long long M = h;
                    if (even_sticks + 1 >= 3 && S > 2LL * M) {
                        best_add1 = max(best_add1, h);
                        break;
                    }
                }
            }
        }
        if (best_add1 > 0) {
            maxPerimeter = max(maxPerimeter, even_sum + best_add1);
        }

        // add 2 only if half size would be odd
        bool can_add2 = ((even_sticks / 2) % 2 == 0);
        if (can_add2) {
            long long best_add2 = 0;
            // two safe
            if (safe_adds.size() >= 2) {
                long long add1 = safe_adds[0], add2 = safe_adds[1];
                long long S = even_sum + add1 + add2;
                long long M = max_always;
                if (even_sticks + 2 >= 3 && S > 2LL * M) {
                    best_add2 = max(best_add2, add1 + add2);
                }
            }
            // one high one safe
            if (!high_adds.empty() && !safe_adds.empty()) {
                long long top_safe = safe_adds[0];
                for (auto h : high_adds) {
                    if (h < even_sum + top_safe) {
                        long long S = even_sum + h + top_safe;
                        long long M = h;
                        if (even_sticks + 2 >= 3 && S > 2LL * M) {
                            best_add2 = max(best_add2, h + top_safe);
                            break;
                        }
                    }
                }
            }
            // two high
            if (high_adds.size() >= 2) {
                for (size_t i = 0; i < high_adds.size() - 1; ++i) {
                    long long larger = high_adds[i], smaller = high_adds[i + 1];
                    if (larger < even_sum + smaller) {
                        long long S = even_sum + larger + smaller;
                        long long M = larger;
                        if (even_sticks + 2 >= 3 && S > 2LL * M) {
                            best_add2 = max(best_add2, larger + smaller);
                        }
                    }
                }
            }
            if (best_add2 > 0) {
                maxPerimeter = max(maxPerimeter, even_sum + best_add2);
            }
        }

        cout << maxPerimeter << "\n";
    }
    return 0;
}