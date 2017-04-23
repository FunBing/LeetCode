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
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        if(l1 == NULL && l2 == NULL)
            return NULL;
        else if(l1 == NULL && l2 != NULL)
            return l2;
        else if(l1 != NULL && l2 == NULL)
            return l1;


        ListNode *head = l1 -> val > l2 -> val ? l2 : l1;
        ListNode *handler = head;
        ListNode *l1Next = head == l1 ? l1 -> next : l1;
        ListNode *l2Next = head == l2 ? l2 -> next : l2;

        while(l1Next != NULL && l2Next != NULL)
        {
            if(l1Next -> val > l2Next -> val)
            {
                handler -> next = l2Next;
                l2Next = l2Next -> next;
            }
            else
            {
                handler -> next = l1Next;
                l1Next = l1Next -> next;
            }
            handler = handler -> next;
        }

        if(l1Next == NULL)
            handler -> next = l2Next;
        else
            handler -> next = l1Next;

        return head;
    }
};
