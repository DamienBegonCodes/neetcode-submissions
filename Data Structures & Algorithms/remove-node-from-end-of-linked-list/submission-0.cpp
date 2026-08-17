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

class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) 
    {
        ListNode * current(head);
        while(n > 0)
        {
            current = current->next;
            --n;
        }

        if (current == nullptr)
        {
            return head->next;
        }

        ListNode * previous(head);

        while (current->next != nullptr)
        {
            current = current->next;
            previous = previous->next;
        }

        previous->next = previous->next->next;
        return head;
    }
};
