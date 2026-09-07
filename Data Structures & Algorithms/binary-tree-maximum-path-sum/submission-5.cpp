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
    int maxPathSum(TreeNode* root) 
    {
        unordered_map<TreeNode *, int> max_paths({{nullptr, 0}});
        stack<TreeNode *> s({root});
        int out(root->val);

        while(!s.empty())
        {
            TreeNode * node(s.top());
            if (!max_paths.contains(node->left))
            {
                s.push(node->left);
            }
            else if(!max_paths.contains(node->right))
            {
                s.push(node->right);
            }
            else
            {
                int sum(max_paths[node->right] + max_paths[node->left] + node->val);
                if (sum > out)
                {
                    out = sum;
                }

                max_paths[node] = max(max(node->val + max_paths[node->right], node->val + max_paths[node->left]), 0);
                s.pop();
            }
        }

        return out;
    }
};
