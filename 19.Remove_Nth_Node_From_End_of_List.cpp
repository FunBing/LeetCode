/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
 //This is the new code after I read the solution
class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode *fast = head, *slow = head;

        while(n-- > 0)
            fast = fast -> next;

        if(fast == NULL)
            return head -> next;

        while(fast -> next != NULL)
        {
            slow = slow -> next;
            fast = fast -> next;
        }



        slow -> next = slow -> next -> next;

        return head;
    }
};
