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
    ListNode* reverseList(ListNode* head, ListNode* stop) 
    {
        ListNode * next_node = stop;
        while(head != stop)
        {
            ListNode * current = head;
            head = head->next;
            current->next = next_node;
            next_node = current;
        }
        return next_node;
    }

    ListNode* reverseKGroup(ListNode* head, int k) 
    {
        ListNode* current(head);
        ListNode* prev_head(nullptr);
        bool first_iteration(true);
        while(current != nullptr)
        {
            ListNode* left(current);
            int counter(0);
            while (counter < k && current != nullptr)
            {
                ++counter;
                current = current->next;
            }
            if (counter < k)
            {
                return head;
            }
            ListNode* khead = reverseList(left, current);
            if (first_iteration)
            {
                head = khead;
                first_iteration = false;
            }
            else
            {
                prev_head->next = khead;
            }
            prev_head = left;
        }
        return head;
    }
};
