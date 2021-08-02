
ListNode *addTwoNumbers(ListNode *l1, ListNode *l2)
{
    ListNode *dummy_head = new ListNode();
    ListNode *temp = dummy_head;
    int carry = 0;
    while (l1 or l2 or carry)
    {
        int sum = 0;
        if (l1)
        {
            sum += l1->val;
            l1 = l1->next;
        }
        if (l2)
        {
            sum += l2->val;
            l2 = l2->next;
        }
        sum += carry;
        carry = sum / 10;
        ListNode *new_node = new ListNode(sum % 10);
        temp->next = new_node;
        temp = temp->next;
    }
    return dummy_head->next;
}