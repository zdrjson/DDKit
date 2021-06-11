class Solution {
public:
    bool buddyStrings(string A, string B) {
        if (A.length() != B.length()) return false;
        vector<int> ca(26);
        vector<int> cb(26);
        int diff = 0;
        for (int i = 0; i < A.length(); ++i) {
            if (A[i] != B[i] && diff++ > 2) return false;
            ++ca[A[i] - 'a'];
            ++cb[B[i] - 'a'];
        }
        for (int i = 0; i < 26; ++i) {
            if (diff == 0 && ca[i] > 1) return true;
            if (ca[i] != cb[i]) return false;
        }
        return diff == 2;
    }
};
