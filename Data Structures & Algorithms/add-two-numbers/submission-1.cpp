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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) 
    {
        ListNode * head(l1);
        ListNode * prev = new ListNode(0, head);
        char carry(0);
        while(l1 != nullptr || l2 != nullptr)
        {
            int val1 = l1 == nullptr ? 0 : l1->val;
            int val2 = l2 == nullptr ? 0 : l2->val;
            int sum = val1 + val2 + carry;
            if (sum / 10 > 0)
            {
                carry = 1;
            }
            else
            {
                carry = 0;
            }

            if (l1 != nullptr)
            {
                l1->val = sum % 10;
            }
            else
            {
                l1 = new ListNode(sum % 10);
                prev->next = l1;
            }

            l1 = l1->next;
            prev = prev->next;
            if (l2 != nullptr)
            {
                l2 = l2->next;
            }
        }
        
        if (carry)
        {
            prev->next = new ListNode(1);
        }
            

        return head;    
    }
};
