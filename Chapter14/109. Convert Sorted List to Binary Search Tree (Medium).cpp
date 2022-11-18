class Solution {
public:
    TreeNode* sortedListToBST(ListNode* head) {
        if (!head) {
            return nullptr;
        }
        if (!head->next) {
            return new TreeNode(head->val);
        }
        ListNode *fast = head, *slow = head, *pre;
        while (fast && fast->next) {
            fast = fast->next->next;
            pre = slow;
            slow = slow->next;
        }
        ListNode *head2 = slow->next;
        pre->next = nullptr;
        TreeNode *root = new TreeNode(slow->val);
        root->left = sortedListToBST(head);
        root->right = sortedListToBST(head2);
        return root;
    }
};
