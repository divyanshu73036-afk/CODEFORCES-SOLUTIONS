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
    ListNode* swapPairs(ListNode* head) {
    if (head == NULL || head->next == NULL)
        return head;

    ListNode* temp = head->next;
    ListNode* prev = NULL;
    ListNode* t1 = head;

    while (t1 != NULL && t1->next != NULL) {

        ListNode* t2 = t1->next;

        // swap
        t1->next = t2->next;
        t2->next = t1;

        // connect previous pair to current pair
        if (prev != NULL)
            prev->next = t2;

        prev = t1;
        t1 = t1->next;
    }

    return temp;
}
};