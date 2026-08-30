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
        
        ListNode*t1=l1;
     ListNode*t2=l2; 
             ListNode*dummy_curr=new ListNode(-1);
             int carry=0;
                     ListNode*temp_curr=dummy_curr;
                     while(t1!=NULL||t2!=NULL){
                        int sum=carry;
                        if(t1)sum+=t1->val;
                        if(t2)sum+=t2->val;
                        ListNode* newlist_node=new ListNode(sum%10);
                        carry=sum/10;
                        temp_curr->next=newlist_node;
                        temp_curr=temp_curr->next;
                        if(t1)t1=t1->next;
                        if(t2)t2=t2->next;
                     }
                     if(carry){
                        ListNode* newlist_node=new ListNode(carry);
                        temp_curr->next= newlist_node;
                     }
                     return dummy_curr->next;
    }
};