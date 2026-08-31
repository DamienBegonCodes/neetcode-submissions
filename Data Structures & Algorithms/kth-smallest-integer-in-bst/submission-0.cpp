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
    int kthSmallest(TreeNode* root, int k) 
    {
        stack<TreeNode*> s({root});
        unordered_set<TreeNode*> visited({nullptr});

        while (!s.empty())
        {
            TreeNode * node(s.top());
            if (node->left == nullptr)
            {
                break;
            }
        }

        int count(1);
        while (!s.empty())
        {
            TreeNode * node(s.top());
            if (!visited.contains(node->left))
            {
                s.push(node->left);
            }
            else if (!visited.contains(node))
            {
                if (count == k)
                {
                    return node->val;
                }
                ++count;
                visited.insert(node);
            }
            else if (!visited.contains(node->right))
            {
                s.push(node->right);
            }
            else
            {
                s.pop();
            }
        }
        return INT_MIN;
    }
};
