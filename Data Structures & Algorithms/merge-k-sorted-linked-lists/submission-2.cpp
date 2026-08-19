/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */

#include <map>
#include <stack>

class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) 
    {
        map<int, stack<ListNode*>> mp;
        for (auto & node : lists)
        {
            if (node != nullptr)
            {
                mp[node->val].push(node);
            }
        }

        ListNode * dummy = new ListNode();
        ListNode * current(dummy);

        while(!mp.empty())
        {
            stack<ListNode*> * nodes = &mp.begin()->second;
            ListNode * node = nodes->top();
            nodes->pop();
            current->next = node;
            if (nodes->empty())
            {
                mp.erase(mp.begin());
            }
            if (node->next != nullptr)
            {
                mp[node->next->val].push(node->next);
            }
            current = current->next;
        }
        return dummy->next;
    }
};
