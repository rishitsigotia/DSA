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
Time Complexity: O(2*max(length of list1,length of list2))

Reason: Uses the same concept of the difference of lengths of two lists.

Space Complexity: O(1)

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


//BRute force
ListNode *getIntersectionNode(ListNode *head1, ListNode *head2)
{
    while(head2 != NULL) {
        node* temp = head1;
        while(temp != NULL) {
            //if both nodes are same
            if(temp == head2) return head2;
            temp = temp->next;
        }
        head2 = head2->next;
    }
    //intersection is not present between the lists return null
    return NULL;
}
Time Complexity: O(m*n)

Reason: For each node in list 2 entire lists 1 are iterated. 

Space Complexity: O(1)

Reason: No extra space is used.

//Better Approach
ListNode *getIntersectionNode(ListNode *head1, ListNode *head2)
{
    unordered_set<node*> st;
    while(head1 != NULL) {
       st.insert(head1);
       head1 = head1->next;
    }
    while(head2 != NULL) {
        if(st.find(head2) != st.end()) return head2;
        head2 = head2->next;
    }
    return NULL;
}
Time Complexity: O(n+m)

Reason: Iterating through list 1 first takes O(n), then iterating through list 2 takes O(m). 

Space Complexity: O(n)

Reason: Storing list 1 node addresses in unordered_set.