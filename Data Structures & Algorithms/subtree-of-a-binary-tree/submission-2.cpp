/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
// Serialize tree and then use KMP algo O(m+n)

class Solution {
public:
    // Helper function to serialize the tree into a unique string format
    string serialize(TreeNode* root) {
        if (root == nullptr) {
            return "$#";
        }
        return "$" + to_string(root->val) +
                serialize(root->left) + serialize(root->right);
    }

    // Helper function to build the Longest Prefix Suffix (LPS) table
    vector<int> build_lps(const string& pattern) {
        int m = pattern.length();
        vector<int> lps(m, 0);
        int length = 0; // Length of the previous longest prefix suffix
        int i = 1;

        while (i < m) {
            if (pattern[i] == pattern[length]) {
                length++;
                lps[i] = length;
                i++;
            } else {
                if (length != 0) {
                    length = lps[length - 1]; // Fallback trick
                } else {
                    lps[i] = 0;
                    i++;
                }
            }
        }
        return lps;
    }

    bool isSubtree(TreeNode* root, TreeNode* subRoot) {
        string text = serialize(root);
        string pattern = serialize(subRoot);

        int n = text.length();
        int m = pattern.length();

        if (m == 0) return true;

        vector<int> lps = build_lps(pattern);
        int i = 0; // Index for text
        int j = 0; // Index for pattern

        while (i < n) {
            if (text[i] == pattern[j]) {
                i++;
                j++;
            }

            if (j == m) {
                return true; // Match found! subRoot is a subtree.
            } 
            else if (i < n && text[i] != pattern[j]) {
                if (j != 0) {
                    j = lps[j - 1]; // Shift pattern using LPS table without backtracking 'i'
                } else {
                    i++;
                }
            }
        }
        return false;
    }
};
