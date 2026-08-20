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
#include <string>
class Solution {
public:
    ListNode* reverseList(ListNode* head, int * counter, int k) 
    {
        ListNode * next_node(nullptr);
        ListNode * right(head);
        while(head != nullptr && *counter < k)
        {
            ListNode * current = head;
            head = head->next;
            current->next = next_node;
            next_node = current;
            ++*counter;
            if (*counter == k)
            {
                right->next = head;
            }
        }
        return next_node;
    }

    ListNode* reverseKGroup(ListNode* head, int k) 
    {
        ListNode* current(head);
        ListNode* prev_head(nullptr);
        bool first_iteration(true);
        while (current != nullptr)
        {
            int counter(0);
            ListNode * khead = reverseList(current, &counter, k);
            if (counter < k)
            {
                counter = 0;
                reverseList(khead, &counter, k);
                return head;
            }
            if (first_iteration)
            {
                head = khead;
                first_iteration = false;
            }
            else
            {
                prev_head->next = khead;
            }
            prev_head = current;
            current = current->next;
        }
        return head;
    }
};
