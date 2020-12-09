class Solution {
public:
    int minimumIncompatibility(vector<int>& nums, int k) {
        const int n = nums.size();
        const int c = n / k;
        int dp[1 << 16][16];
        memset(dp, 0x7f, sizeof(dp));
        for (int i = 0; i < n; ++i) dp[1 << i][i] = 0;
        for (int s = 0; s < 1 << n; ++s)
            for (int i = 0; i < n; ++i) {
                if ((s & (1 << i)) == 0) continue;
                for (int j = 0; j < n; ++j) {
                    if ((s & (1 << j))) continue;
                    const int t = s | (1 << j);
                    if (__builtin_popcount(s) % c == 0) {
                        dp[t][j] = min(dp[t][j], dp[s][i]);
                    } else if (nums[j] > nums[i]) {
                        dp[t][j] = min(dp[t][j],
                                       dp[s][i] + nums[j] - nums[i]);
                    }
                }
            }
        int ans = *min_element(begin(dp[(1 << n) - 1]),
                               end(dp[(1 << n) - 1]));
        return ans > 1e9 ? - 1 : ans;
    }
};
