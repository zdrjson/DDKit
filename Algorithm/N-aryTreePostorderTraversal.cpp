/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};
*/
// // Solution 1: Recursive
// class Solution {
// public:
//     vector<int> postorder(Node* root) {
//         vector<int> ans;
//         postorder(root, ans);
//         return ans;
//     }
// private:
//     void postorder(Node* root, vector<int>& ans) {
//         if (!root) return;
//         for (auto child : root->children)
//             postorder(child, ans);
//         ans.push_back(root->val);
//     }
// };

// Solution 2: Iterative
class Solution {
public:
    vector<int> postorder(Node* root) {
        if (!root) return {};
        vector<int> ans;
        stack<Node*> s;
        s.push(root);
        while (!s.empty()) {
            const Node* node = s.top(); s.pop();
            ans.push_back(node->val);
            for (auto child : node->children)
                s.push(child);
        }
        reverse(begin(ans), end(ans));
        return ans;
    }
};
