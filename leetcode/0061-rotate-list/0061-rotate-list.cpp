/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* rotateRight(ListNode* head, int k) {

        if (head == NULL || head->next == NULL)
            return head;

        int len = 1;
        ListNode* tail = head;

        while (tail->next != NULL) {
            tail = tail->next;
            len++;
        }

        k = k % len;

        if (k == 0)
            return head;

        ListNode* temp = head;

        int count = len - k - 1;

        while (count > 0) {
            temp = temp->next;
            count--;
        }

        ListNode* newhead = temp->next;

        temp->next = NULL;

        // IMPORTANT
        tail->next = head;

        return newhead;
    }
};