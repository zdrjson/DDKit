// // Solution: DP
// // Time complexity: O(n^2)
// // Space complexity: O(n^2)
// class Solution {
// public:
//     bool wordBreak(string s, vector<string>& wordDict) {
//         // Create a hashset of words for fast query.
//         unordered_set<string> dict(wordDict.cbegin(), wordDict.cend());
//         // Query the answer of the original string.
//         return wordBreak(s, dict);
//     }
    
//     bool wordBreak(const string& s, const unordered_set<string>& dict) {
//         // In memory, directly return.
//         if (mem_.count(s)) return mem_[s];
//         // Whole string is a word, memorize and return.
//         if (dict.count(s)) return mem_[s] = true;
//         // Try every break point.
//         for (int j = 1; j < s.length(); ++j) {
//             const string left = s.substr(0, j);
//             const string right = s.substr(j);
//             // Find the solution for s.
//             if (dict.count(right) && wordBreak(left, dict))
//                 return mem_[s] = true;
//         }
//         // No solution for s, memorize and return.
//         return mem_[s] = false;
//     }
// private:
//     unordered_map<string, bool> mem_;
// };

// C++ V2 without using dict.
class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        // Mark every word as breakable.
        for (const string& word : wordDict)
            mem_.emplace(word, true);
        
        // Query the answer of the original string.
        return wordBreak(s);
    }
    
    bool wordBreak(const string& s) {
        // In memory, directly return.
        if (mem_.count(s)) return mem_[s];
        
        // Try every break point.
        for (int j = 1; j < s.length(); ++j) {
            auto it = mem_.find(s.substr(j));
            // Find the solution for s.
            if (it != mem_.end() && it->second && wordBreak(s.substr(0, j)))
                return mem_[s] = true;
        }
        
        // No solution for s, memorize and return.
        return mem_[s] = false;
    }
private:
    unordered_map<string, bool> mem_;
};
