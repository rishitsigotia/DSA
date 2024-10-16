// Most optimal solution
// changing d1 and d2 will cover the extra length which is remaining.
ListNode *getIntersectionNode(ListNode *headA, ListNode *headB)
{
    // edge case
    if (headA == NULL || headB == NULL)
        return NULL;

    ListNode *d1 = headA;
    ListNode *d2 = headB;

    while (d1 != d2) // if there is no intersection they will both become null at same time.
    {
        d1 = d1 == NULL ? headB : d1->next;
        d2 = d2 == NULL ? headA : d2->next;
    }
    return d1;
}

// Second optimal approach same TC but longer code
ListNode *getIntersectionNode(ListNode *headA, ListNode *headB)
{
    // edge case
    if (headA == NULL || headB == NULL)
        return NULL;

    ListNode *d1 = headA;
    ListNode *d2 = headB;

    int n = 0, m = 0, difference;
    while (d1)
    {
        d1 = d1->next;
        n++;
    }
    while (d2)
    {
        d2 = d2->next;
        m++;
    }

    d1 = headA;
    d2 = headB;

    if (m > n)
    {
        difference = m - n;
        while (difference)
        {
            d2 = d2->next;
            difference--;
        }
    }
    else
    {
        difference = n - m;
        while (difference)
        {
            d1 = d1->next;
            difference--;
        }
    }

    while (d1 != d2)
    {
        d1 = d1->next;
        d2 = d2->next;
    }
    return d1;
}