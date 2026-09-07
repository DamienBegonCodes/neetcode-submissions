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

class Solution {
public:
    int recursive_maxPathSum(TreeNode * root, int * max_path_sum)
    {
        int left(0), right(0);
        if (root->left != nullptr)
        {
            left = max(recursive_maxPathSum(root->left, max_path_sum), 0);
        }
        if (root->right != nullptr)
        {
            right = max(recursive_maxPathSum(root->right, max_path_sum), 0);
        }

        int sum(left + right + root->val);
        if (sum > *max_path_sum)
        {
            *max_path_sum = sum;
        }
        return max(root->val + left, root->val + right);
    }

    int maxPathSum(TreeNode* root) 
    {
        int out(root->val);
        recursive_maxPathSum(root, &out);
        return out;
    }
};
