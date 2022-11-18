class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
        if (!head) return nullptr;
        ListNode *slow = head, *fast = head;
        while (fast) {
            if (fast->val != slow->val) {
                slow->next = fast;
                slow = fast;
            }
            fast = fast->next;
        }
        slow->next = nullptr;
        return head;
    }
};
