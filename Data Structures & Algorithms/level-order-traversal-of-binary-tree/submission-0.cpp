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

#include <deque>
#include <utility>

class Solution {
public:
    vector<vector<int>> levelOrder(TreeNode* root) 
    {
        if (root == nullptr)
        {
            return {};
        }

        vector<vector<int>> out;
        deque<pair<TreeNode*, int>> dq({{root, 0}});
        int current_lvl(-1);
        while (!dq.empty())
        {
            TreeNode * node = dq.front().first;
            int level = dq.front().second;
            dq.pop_front();

            if (level > current_lvl)
            {
                current_lvl = level;
                out.push_back({});
            }
            out[out.size() - 1].push_back(node->val);


            if (node->left != nullptr)
            {
                dq.push_back({node->left, level + 1});
            }
            
            if (node->right != nullptr)
            {
                dq.push_back({node->right, level + 1});
            }
        }
        return out;
    }
};
