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

#include <unordered_map>
#include <stack>

class Solution {
public:
    bool isBalanced(TreeNode* root) 
    {
        if (root == nullptr)
        {
            return true;
        }
        unordered_map<TreeNode*, int> hm({{nullptr, 0}});
        stack<TreeNode*> s({root});

        while (!s.empty())
        {
            TreeNode * node(s.top());
            if (node->left != nullptr && !hm.contains(node->left))
            {
                s.push(node->left);
            }
            else if (node->right != nullptr && !hm.contains(node->right))
            {
                s.push(node->right);
            }
            else
            {
                s.pop();
                if (abs(hm[node->left] - hm[node->right]) > 1)
                {
                    return false;
                }
                hm[node] = max(hm[node->left], hm[node->right]) + 1;
            }
        }
        return true;
    }
};
