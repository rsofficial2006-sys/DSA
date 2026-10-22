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
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        if (left == right) return head;

        ListNode* dummy = new ListNode(0);
        dummy->next = head;

        
        ListNode* prev = dummy;

        for (int i = 1; i < left; i++) {
            prev = prev->next;
        }

        
        ListNode* curr = prev->next;
        ListNode* subTail = curr;
        ListNode* revPrev = nullptr;

        for (int i = 0; i < right - left + 1; i++) {
            ListNode* nextNode = curr->next;
            curr->next = revPrev;
            revPrev = curr;
            curr = nextNode;
        }

        
        prev->next = revPrev;
        subTail->next = curr;

        return dummy->next;
    }
};
