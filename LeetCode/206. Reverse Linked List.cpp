ListNode* reverseList(ListNode* head) {
        if(head == NULL || head->next == NULL)
            return head;

        ListNode* curr = head;
        ListNode* prev = NULL;
        ListNode* nxt;

        while(curr)
        {
            nxt = curr->next; // have to maintain a link 
            curr->next = prev; // b/w next and previous node.
            prev = curr;
            curr = nxt;
        }
        return prev;

    }