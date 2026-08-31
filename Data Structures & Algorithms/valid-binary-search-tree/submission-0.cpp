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

#include <stack>
#include <utility>

class Solution {
public:
    bool isValidBST(TreeNode* root) 
    {
        stack<pair<TreeNode*, pair<int, int>>> s({{root, {INT_MIN, INT_MAX}}});

        while (!s.empty())
        {
            TreeNode * node(s.top().first);
            pair<int, int> window(s.top().second);
            s.pop();

            if (node->val <= window.first || node->val >= window.second)
            {
                return false;
            }
            if (node->left != nullptr)
            {
                s.push({node->left, {window.first, node->val}});
            }
            if (node->right != nullptr)
            {
                s.push({node->right, {node->val, window.second}});
            }
        }

        return true;
    }
};
