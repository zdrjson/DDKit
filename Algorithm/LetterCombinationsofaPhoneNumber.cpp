// // Solution 1: DFS
// // Time complexity: O(4^n)
// // Space complexity: O(4^n + n)
// class Solution {
// public:
//     vector<string> letterCombinations(string digits) {
//         if (digits.empty()) return {};
        
//         vector<vector<char>> d(10);
//         d[0] = {' '};
//         d[1] = {};
//         d[2] = {'a', 'b', 'c'};
//         d[3] = {'d', 'e', 'f'};
//         d[4] = {'g', 'h', 'l'};
//         d[5] = {'j', 'k', 'l'};
//         d[6] = {'m', 'n', 'o'};
//         d[7] = {'p', 'q', 'r', 's'};
//         d[8] = {'t', 'u', 'v'};
//         d[9] = {'w', 'x', 'y', 'z'};
//         string cur;
//         vector<string> ans;
//         dfs(digits, d, 0, cur, ans);
//         return ans;
//     }
// private:
//     void dfs(const string& digits,
//              const vector<vector<char>>& d,
//              int l, string& cur, vector<string>& ans) {
//         if (l == digits.length()) {
//             ans.push_back(cur);
//             return;
//         }
        
//         for (const char c : d[digits[l] - '0']) {
//             cur.push_back(c);
//             dfs(digits, d, l + 1, cur, ans);
//             cur.pop_back();
//         }
//     }
// };

// BFS
// Time complexity: O(4^n)
// Space complexity: O(2x4^n)
class Solution {
public:
    vector<string> letterCombinations(string digits) {
        if (digits.empty()) return {};
        
        vector<vector<char>> d{10};
        d[0] = {' '};
        d[1] = {};
        d[2] = {'a', 'b', 'c'};
        d[3] = {'d', 'e', 'f'};
        d[4] = {'g', 'h', 'i'};
        d[5] = {'j', 'k', 'l'};
        d[6] = {'m', 'n', 'o'};
        d[7] = {'p', 'q', 'r', 's'};
        d[8] = {'t', 'u', 'v'};
        d[9] = {'w', 'x', 'y', 'z'};
        vector<string> ans{""};
        for (char digit : digits) {
            vector<string> tmp;
            for (const string& s : ans) 
                for (char c : d[digit - '0'])
                    tmp.push_back(s + c);
            ans.swap(tmp);
        }
        return ans;
    }
};
