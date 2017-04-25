/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
 //This is my own code
class Solution {
public:
    ListNode* swapPairs(ListNode* head) {
        if(head == NULL || head -> next == NULL)
            return head;

        ListNode *tmp1 = head;
        ListNode *tmp2 = head -> next;

        head = head -> next;
        while(tmp2 -> next != NULL && tmp2 -> next -> next != NULL)
        {
            tmp2 = tmp2 -> next;
            tmp1 -> next -> next = tmp1;
            tmp1 -> next = tmp2 -> next;
            tmp1 = tmp2;
            tmp2 = tmp2 -> next;
        }

        if(tmp2 -> next == NULL)
        {
            tmp1 -> next -> next = tmp1;
            tmp1 -> next = NULL;
            return head;
        }
        else if(tmp2 -> next -> next == NULL)
        {
            tmp2 = tmp2 -> next;
            tmp1 -> next -> next = tmp1;
            tmp1 -> next = tmp2;

            return head;
        }

    }
};
