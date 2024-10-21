bool isPalindrome(ListNode *head)
{
    if (head == NULL || head->next == NULL)
        return true;

    ListNode *slow = head;
    ListNode *fast = head;

 //find the middle element , to reverse the next half
    while (fast->next != NULL && fast->next->next != NULL)
    {
        slow = slow->next;
        fast = fast->next->next;
    }
    // revesing the next half for the comparision
    slow->next = reverse(slow->next);
    slow = slow->next;
    ListNode *dummy = head; // now compare from start to mid, slow is in mid + 1 

    while (slow != NULL)
    {
        if (dummy->val != slow->val) // if we found any value that is not equal we will show false.
            return false;
        dummy = dummy->next;
        slow = slow->next;
    }
    return true;
}

ListNode *reverse(ListNode *ptr)
{
    ListNode *pre = NULL;
    ListNode *nex = NULL;

    while (ptr != NULL)
    {
        nex = ptr->next;
        ptr->next = pre;
        pre = ptr;
        ptr = nex;
    }
    return pre;
}