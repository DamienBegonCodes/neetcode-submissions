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
    
    //  Brute force with deque :
    //      O(n) time
    //      O(n) space
    // 
    // void reorderList(ListNode* head) 
    // {
    //     deque<ListNode*> nodes;
    //     while(head != nullptr)
    //     {
    //         nodes.push_back(head);
    //         head = head->next;
    //     }

    //     ListNode * front = nodes.front();
    //     ListNode * back = nodes.back();
    //     while(front->next != back && front != back)
    //     {
    //         front->next = back;
    //         nodes.pop_front();
    //         front = nodes.front();
    //         back->next = front;
    //         nodes.pop_back();
    //         back = nodes.back();
    //     }
    //     back->next = nullptr;
    // }

    // Reverse and merge :
    //      O(n) time
    //      O(1) space

    ListNode* reverseList(ListNode* head) 
    {
        ListNode * next_node = nullptr;
        while(head != nullptr)
        {
            ListNode * current = head;
            head = head->next;
            current->next = next_node;
            next_node = current;
        }
        return next_node;
    }

    void reorderList(ListNode* head)
    {
        ListNode * slow(head);
        ListNode * fast(head->next);

        while (fast != nullptr && fast->next != nullptr)
        {
            slow = slow->next;
            fast = fast->next->next;
        }

        ListNode * second_half = slow->next;
        slow->next = nullptr;

        second_half = reverseList(second_half);
        while(second_half != nullptr)
        {
            ListNode * next_first_half = head->next;
            head->next = second_half;
            ListNode * next_second_half = second_half->next;
            second_half->next = next_first_half;
            head = next_first_half;
            second_half = next_second_half;
        }
    }
};
