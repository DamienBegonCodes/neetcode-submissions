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
    int max_len(TreeNode* root, int * max_diameter)
    {
        int left_len(0), right_len(0);
        if (root->left != nullptr)
        {
            left_len = max_len(root->left, max_diameter);
        }
        if (root->right != nullptr)
        {
            right_len = max_len(root->right, max_diameter);
        }
        if (left_len + right_len > *max_diameter)
        {
            *max_diameter = left_len + right_len;
        }
        return max(left_len, right_len) + 1;
    }

    int diameterOfBinaryTree(TreeNode* root) 
    {
        if (root == nullptr)
        {
            return 0;
        }
        int max_diameter(0);

        max_len(root, &max_diameter);
        return max_diameter;
    }
};
