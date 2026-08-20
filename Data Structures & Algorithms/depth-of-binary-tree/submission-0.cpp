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
    int maxDepth(TreeNode* root) 
    {
        if (root == nullptr)
        {
            return 0;
        }
        stack<pair<TreeNode*, int>> s({{root, 1}});
        int out(0);
        
        while (!s.empty())
        {
            TreeNode* node = s.top().first;
            int depth = s.top().second;
            s.pop();

            if (depth > out)
            {
                out = depth;
            }

            if (node->left != nullptr)
            {
                s.push({node->left, depth + 1});
            }
            if (node->right != nullptr)
            {
                s.push({node->right, depth + 1});
            }
        }
        return out;
    }
};
