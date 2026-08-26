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
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q)
    {
        stack<TreeNode*> s1({root}), s2;
        unordered_set<TreeNode*> visited({nullptr});

        while (!s1.empty())
        {
            TreeNode * node(s1.top());
            
            if ((node == p || node == q) && !visited.contains(node))
            {
                if (s2.empty())
                {
                    s2 = s1;
                }
                else
                {
                    break;
                }
            }

            if (!visited.contains(node->left))
            {
                s1.push(node->left);
            }
            else if (!visited.contains(node->right))
            {
                s1.push(node->right);
            }
            else
            {
                s1.pop();
            }
            visited.insert(node);
        }
        // cout << "###### STACK 1 ######" << endl;
        // while (!s1.empty())
        // {
        //     cout << s1.top()->val << ", ";
        //     s1.pop();
        // }
        // cout << endl;
        // cout << "###### STACK 2 ######" << endl;
        // while (!s2.empty())
        // {
        //     cout << s2.top()->val << ", ";
        //     s2.pop();
        // }
        // cout << endl;
        // return root;

        if (s2.size() > s1.size())
        {
            swap(s1, s2);
        }

        while (s1.size() > s2.size())
        {
            s1.pop();
        }

        while (s1.top() != s2.top())
        {
            s1.pop();
            s2.pop();
        }

        return s1.top();
    }
};
