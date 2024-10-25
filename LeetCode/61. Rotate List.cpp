ListNode* rotateRight(ListNode* head, int k) 
    {
        int n = 1;
        if(head == NULL || head->next == NULL)
            return head;
        ListNode *temp  = head;
        while(temp->next)
        {
            n++;
            temp = temp->next;
        }
        temp->next = head;
        k = k%n;
        cout << n << k;
        int newTail = n-k;
        // new Tail and new Head we have to find 
        // if we use dummyNode than we have to start with 
        // and stop at newTail - 1 
        //because to reach 3 we have to do 2 iteration.
        for(int i = newTail ; i > 0; i--)
        {
            temp = temp->next;
        }
        head = temp->next;
        temp->next = NULL;
        return head;
}