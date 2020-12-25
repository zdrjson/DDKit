class Solution {
public:
    int stoneGameVI(vector<int>& A, vector<int>& B) {
        const int n = A.size();
        vector<pair<int, int>> s(n);
        for (int i = 0; i < n; ++i)
            s.emplace_back(A[i] + B[i], i);
        sort(rbegin(s), rend(s));
        int ans = 0;
        for (int i = 0; i < n; ++i) {
            int idx = s[i].second;
            ans += (i & 1 ? B[idx] : A[idx]) * (i & 1 ? -1 : 1);
        }
        return ans < 0 ? -1 : (ans > 0);
    }
};
