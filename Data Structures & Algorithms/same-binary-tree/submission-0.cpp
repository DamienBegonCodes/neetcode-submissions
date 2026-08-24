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

class Solution {
public:
    bool isSameTree(TreeNode* p, TreeNode* q) 
    {
        stack<pair<TreeNode*, TreeNode*>> s({{p, q}});

        while (!s.empty())
        {
            TreeNode* node_1 = s.top().first;
            TreeNode* node_2 = s.top().second;
            s.pop();

            if (node_1 == nullptr && node_2 == nullptr)
            {
                continue;
            }
            else if (node_1 == nullptr || node_2 == nullptr || node_1->val != node_2->val)
            {
                return false;
            }
            s.push({node_1->left, node_2->left});
            s.push({node_1->right, node_2->right});
        }
        return true;
    }
};
