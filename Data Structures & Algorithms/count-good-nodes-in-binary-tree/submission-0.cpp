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
#include <unordered_set>

class Solution {
public:
    int goodNodes(TreeNode* root) 
    {
        int out(0);
        stack<int> max_stack;
        stack<TreeNode*> s({root});
        unordered_set<TreeNode*> visited({nullptr});

        while (!s.empty())
        {
            TreeNode * node = s.top();
            if (!visited.contains(node))
            {
                if (max_stack.empty() || max_stack.top() <= node->val)
                {
                    ++out;
                    max_stack.push(node->val);
                }
                if (!visited.contains(node->left))
                {
                    s.push(node->left);
                }
                if (!visited.contains(node->right))
                {
                    s.push(node->right);
                }
                visited.insert(node);
            }
            else
            {
                if (max_stack.top() == node->val)
                {
                    max_stack.pop();
                }
                s.pop();
            }
        }
        return out;
    }
};
