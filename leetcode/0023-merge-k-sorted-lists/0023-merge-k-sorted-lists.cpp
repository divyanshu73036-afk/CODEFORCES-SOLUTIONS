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
ListNode*merge_2_list(ListNode*h1,ListNode*h2){
    ListNode*t1=h1;
    ListNode*t2=h2;
    ListNode*dummynode=new ListNode(-1);
    ListNode*temp=dummynode;
    while(t1!=NULL&&t2!=NULL){
        if(t1->val<t2->val){
            temp->next=t1;
            temp=t1;
            t1=t1->next;
        }
        else{
            temp->next=t2;
            temp=t2;
            t2=t2->next;
        }
    }
    if(t1)temp->next=t1;
    if(t2)temp->next=t2;
    return dummynode->next;
}
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        if(lists.size()==NULL)return {};
        ListNode*head=lists[0];
        for(int i=1;i<lists.size();i++){
            head=merge_2_list(head,lists[i]);
        }
        return head;
    }
};