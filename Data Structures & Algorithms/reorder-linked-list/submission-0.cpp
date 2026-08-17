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

#include <deque>

class Solution {
public:
    void reorderList(ListNode* head) 
    {
        deque<ListNode*> nodes;
        while(head != nullptr)
        {
            nodes.push_back(head);
            head = head->next;
        }

        ListNode * front = nodes.front();
        ListNode * back = nodes.back();
        while(front->next != back && front != back)
        {
            front->next = back;
            nodes.pop_front();
            front = nodes.front();
            back->next = front;
            nodes.pop_back();
            back = nodes.back();
        }
        back->next = nullptr;
    }
};
