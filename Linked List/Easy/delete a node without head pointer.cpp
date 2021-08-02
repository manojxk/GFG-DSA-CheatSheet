class Solution {
public:
    void deleteNode(ListNode* node) {
        ListNode *temp = node->next;
        node->next = temp->next;
        node->val = temp->val;
        delete temp;
        
    }
};