//Not a easy question will require dry run multiple times.
// the for loop condition you should know.
ListNode* reverseKGroup(ListNode* head, int k) {
        if(head == NULL || k == 1)
            return head;
        
        ListNode* dummy = new ListNode(0);
        dummy->next = head;

        ListNode* curr = dummy, *pre = dummy , *nxt = dummy;
        int count = 0;
        while(curr->next)
        {
            curr = curr->next;
            count++;
        }
        while(count >= k)
        {
            curr = pre->next;
            nxt = curr->next;

            for(int i = 1 ;i < k; i++ )
            {
                curr->next = nxt->next;
                nxt->next = pre->next;
                pre->next = nxt;
                nxt = curr->next;
            }
            pre = curr;
            count -= k;

        }
        return dummy->next;

    }