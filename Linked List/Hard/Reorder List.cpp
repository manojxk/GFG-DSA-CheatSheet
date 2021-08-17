#include <bits/stdc++.h>
using namespace std;

struct ListNode
{
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};
ListNode *reverse(ListNode *head)
{
    ListNode *current = head;
    ListNode *prev = nullptr, *next = nullptr;
    while (current != nullptr)
    {
        // Store next
        next = current->next;
        // Reverse current node's pointer
        current->next = prev;
        // Move pointers one position ahead.
        prev = current;
        current = next;
    }
    return prev;
}
void reorderList(ListNode *head)
{
    if (head == nullptr)
    {
        return;
    }

    // Find the middle node
    ListNode *slow = head, *fast = head->next;
    while (fast != nullptr && fast->next != nullptr)
    {
        slow = slow->next;
        fast = fast->next->next;
    }

    // Reverse the second half
    ListNode *head2 = reverse(slow->next);
    slow->next = nullptr;

    // Link the two halves together
    while (head != nullptr && head2 != nullptr)
    {
        ListNode* tmp1 = head->next;
        ListNode* tmp2 = head2->next;
        head2->next = head->next;
        head->next = head2;
        head = tmp1;
        head2 = tmp2;
    }
}
