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

    bool isSubtree(TreeNode* root, TreeNode* subRoot) 
    {
        stack<TreeNode*> to_visit({root});

        while(!to_visit.empty())
        {
            TreeNode * node(to_visit.top());
            to_visit.pop();
            if (node == nullptr)
            {
                continue;
            }
            to_visit.push(node->left);
            to_visit.push(node->right);

            if (isSameTree(node, subRoot))
            {
                return true;
            }
        }
        return false;
    }
};
