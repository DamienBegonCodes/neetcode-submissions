/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

#include <unordered_map>

class Solution {
public:
    Node* copyRandomList(Node* head) 
    {
        unordered_map<Node*, Node*> original_to_copy({{nullptr, nullptr}});
        Node * current(head);

        while(current != nullptr)
        {
            Node * new_current;
            Node * new_next;
            Node * new_random;

            if (original_to_copy.contains(current))
            {
                new_current = original_to_copy[current];
            }
            else
            {
                new_current = new Node(current->val);
                original_to_copy[current] = new_current;
            }
            
            if (original_to_copy.contains(current->next))
            {
                new_next = original_to_copy[current->next];
            }
            else
            {
                new_next = new Node(current->next->val);
                original_to_copy[current->next] = new_next;
            }

            new_current->next = new_next;

            if (original_to_copy.contains(current->random))
            {
                new_random = original_to_copy[current->random];
            }
            else
            {
                new_random = new Node(current->random->val);
                original_to_copy[current->random] = new_random;
            }

            new_current->random = new_random;
            current = current->next;
            
        }

        return original_to_copy[head];
    }
};
