/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode* rotateRight(ListNode* head, int k) {
        if(head == nullptr || head -> next == nullptr)
            return head;

        int length = 1;
        ListNode *tail = head, *newHead;
        while(tail -> next != nullptr)
        {
            tail = tail -> next;
            length++;
        }
        tail -> next = head;

        int counter = (length - k % length) % length;
        while(counter--)
        {
            tail = tail -> next;
        }
        newHead = tail -> next;
        tail -> next = nullptr;

        return newHead;
    }
};
