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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        stack<int>s1;
        stack<int>s2;
        ListNode*t1=l1;
        ListNode*t2=l2;
        while(t1!=NULL||t2!=NULL){
            if(t1!=NULL){
            s1.push(t1->val);
            t1=t1->next;
            }
            if(t2!=NULL){
            s2.push(t2->val);
            t2=t2->next;
            }
        }
        ListNode* head = NULL;
        int carry = 0;
        while(!s1.empty() || !s2.empty() || carry) {
    int a = 0;
    int b = 0;
    if(!s1.empty()) {
        a = s1.top();
        s1.pop();
    }
    if(!s2.empty()) {
        b = s2.top();
        s2.pop();
    }
    int sum = a + b + carry;
    int digit = sum % 10;
    carry = sum / 10;
    ListNode* newnode = new ListNode(digit);
    newnode->next = head;//its like creating backward list
    head = newnode;//We are creating the result in backward order, because addition starts from the last digit.
}
        return head;
    }
};