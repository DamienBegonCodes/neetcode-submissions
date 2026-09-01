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
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) 
    {
        return buildTreeRec(preorder.begin(), preorder.end(), inorder.begin(), inorder.end());
    }

    TreeNode * buildTreeRec(    vector<int>::iterator pre_begin, 
                                vector<int>::iterator pre_end, 
                                vector<int>::iterator in_begin, 
                                vector<int>::iterator in_end)
    {
        if (pre_begin == pre_end || in_begin == in_end)
        {
            return nullptr;
        }
        TreeNode * root(new TreeNode(*pre_begin));
        int count(0);
        vector<int>::iterator in_mid(in_begin);
        while (in_mid != in_end && *in_mid != *pre_begin)
        {
            ++in_mid;
            ++count;
        }
        
        root->left = buildTreeRec(pre_begin + 1, pre_begin + count + 1, in_begin, in_mid);
        root->right = buildTreeRec(pre_begin + count + 1, pre_end, in_mid + 1, in_end);
        return root;
    }
};
