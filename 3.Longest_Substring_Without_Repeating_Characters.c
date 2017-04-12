int lengthOfLongestSubstring(char* s) {
    struct list
    {
        int val;
        struct list *next;
    };

    struct list *listForS, *startOfListForS, *tempOfListForS;
    int longForNow = 1, longMost = 1, i = 1, j = 0, num, flag;

    if(s[0] == '\0')
        return 0;

    startOfListForS = listForS = (struct list *)malloc(sizeof(struct list));
    listForS -> val = s[0] - 'a';
    listForS -> next = NULL;
    while(s[i] != '\0')
    {
        num = s[i] - 'a';
        j = 0;

        tempOfListForS = startOfListForS;
        while(tempOfListForS != NULL)
        {
            j++;
            if(num == (tempOfListForS -> val))
            {
                if(tempOfListForS -> next == NULL)
                {
                    startOfListForS = (struct list *)malloc(sizeof(struct list));
                    listForS = startOfListForS;
                    listForS -> val = num;
                    listForS -> next = NULL;
                }
                else
                {
                    startOfListForS = tempOfListForS -> next;
                    listForS -> next = (struct list *)malloc(sizeof(struct list));
                    listForS = listForS -> next;
                    listForS -> val = num;
                    listForS -> next = NULL;
                }

                longMost = longMost < longForNow ? longForNow : longMost;
                longForNow -= j;
                flag = 1;
                break;
            }

            tempOfListForS = tempOfListForS -> next;
        }


        longForNow++;
        if(flag == 0)
        {
            listForS -> next = (struct list *)malloc(sizeof(struct list));
            listForS = listForS -> next;

            listForS -> val = num;
            listForS -> next = NULL;
        }
        flag = 0;
        i++;
    }

    listForS = startOfListForS;
    while(listForS != NULL)
    {
        listForS = listForS -> next;
    }

    longMost = longMost < longForNow ? longForNow : longMost;

    return longMost;
}
