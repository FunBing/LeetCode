/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* addTwoNumbers(struct ListNode* l1, struct ListNode* l2) {
    struct ListNode *result, *ptrResult;
    int temp, flag;

    result = ptrResult = (struct ListNode *)malloc(sizeof(struct ListNode));
    result -> val = 0;
    result -> next = NULL;

    while(l1 != NULL && l2 != NULL)
    {
        temp = ptrResult -> val + (l1 -> val + l2 -> val) % 10;
        flag = temp / 10;
        ptrResult -> val = temp % 10;
        ptrResult -> next = (struct ListNode *)malloc(sizeof(struct ListNode));
        ptrResult = ptrResult -> next;
        //前面的/10检查的是l1 + l2 > 10， 后面的检查的是进位项与l1、l2相加大于10
        ptrResult -> val = (l1 -> val + l2 -> val) / 10 + flag;
        ptrResult -> next = NULL;
        l1 = l1 -> next;
        l2 = l2 -> next;
    }

    while(l1 != NULL)
    {
        temp = ptrResult -> val + (l1 -> val) % 10;
        flag = temp / 10;
        ptrResult -> val = temp % 10;
        ptrResult -> next = (struct ListNode *)malloc(sizeof(struct ListNode));
        ptrResult = ptrResult -> next;
        ptrResult -> val = flag;
        ptrResult -> next = NULL;
        l1 = l1 -> next;
    }

    while(l2 != NULL)
    {
        temp = ptrResult -> val + (l2 -> val) % 10;
        flag = temp / 10;
        ptrResult -> val = temp % 10;
        ptrResult -> next = (struct ListNode *)malloc(sizeof(struct ListNode));
        ptrResult = ptrResult -> next;
        ptrResult -> val = flag;
        ptrResult -> next = NULL;
        l2 = l2 -> next;
    }


    ptrResult = result;
    while((ptrResult -> next) -> next != NULL)
    {
        ptrResult = ptrResult -> next;
    }

    if((ptrResult -> next) -> val == 0)
    {
        free(ptrResult -> next);
        ptrResult -> next = NULL;
    }

    //This is for a test
    /*
    ptrResult = result;
    while(ptrResult != NULL)
    {
        printf("%i ", ptrResult -> val);
        ptrResult = ptrResult -> next;
    }
    */

    return result;

}
