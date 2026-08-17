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

#include <unordered_set>

class Solution {
public:
    bool hasCycle(ListNode* head) 
    {
        unordered_set<ListNode *> node_set;
        while(head != nullptr)
        {
            if (node_set.contains(head))
            {
                return true;
            }
            node_set.insert(head);
            head = head->next;
        }
        return false;
    }
};
