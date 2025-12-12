#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    long long numSubarrayWithMajority(vector<int>& nums, int target) {
        int n = nums.size();
        vector<int> prefix(n + 1, 0);
        for (int i = 1; i <= n; ++i)
            prefix[i] = prefix[i - 1] + (nums[i - 1] == target ? 1 : 0);

        if (prefix[n] == 0) return 0; // target never appears

        long long ans = 0;
        for (int i = 0; i < n; ++i) {
            for (int j = i; j < n; ++j) {
                int cnt = prefix[j + 1] - prefix[i];
                int len = j - i + 1;
                if (cnt > len / 2) ++ans;
            }
        }
        return ans;
    }
};
