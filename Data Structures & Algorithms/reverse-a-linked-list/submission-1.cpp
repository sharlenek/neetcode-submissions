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
    ListNode* reverseList(ListNode* head) {
        if (head == nullptr){
            return nullptr;
        }
        ListNode *prev = nullptr;
        ListNode *curr = head;
        ListNode *nextNode = head->next;

        // 0 1 2 3 4 

        while (curr != nullptr){
            curr->next = prev;
            prev = curr;
            curr = nextNode;
            nextNode = curr->next;

        }
        return prev;
        
    }
};
