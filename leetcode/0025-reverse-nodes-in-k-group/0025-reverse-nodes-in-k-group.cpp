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
 ListNode* reverse( ListNode*head){
    if(head==NULL||head->next==NULL)return head;
     ListNode*newhead=reverse(head->next);
      ListNode*front=head->next;
      front->next=head;
      head->next=NULL;
      return newhead;
 }
    ListNode*getkthelement(ListNode* temp,int k){
        k--;
        while(k>0&&temp!=NULL){
              temp=temp->next;
            k--;
        }
        return temp;
    }
    ListNode* reverseKGroup(ListNode* head, int k) {
         ListNode*temp=head;
          ListNode*prev_node=NULL;
          while(temp!=NULL){
        ListNode* kthelement=getkthelement(temp, k);
        if(kthelement==NULL){
            if(prev_node)prev_node->next=temp;
            break;
        }
         ListNode* nextnode=kthelement->next;
         kthelement->next=NULL;
         reverse(temp);
         if(temp==head)head=kthelement;
         else prev_node->next=kthelement;
          prev_node=temp;
          temp=nextnode;
    }
    return head;
    }
};