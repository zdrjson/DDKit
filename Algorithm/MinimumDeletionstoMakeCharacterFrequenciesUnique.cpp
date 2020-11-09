class Solution {
public:
    int minDeletions(string s) {
        vector<int> freq(26);
        for (char c : s) ++freq[c - 'a'];
        unordered_set<int> seen;
        int ans = 0;
        for (int f : freq) {
            while (f && !seen.insert(f).second) {
                --f;
                ++ans;
            }
        }
        return ans;
    }
};
