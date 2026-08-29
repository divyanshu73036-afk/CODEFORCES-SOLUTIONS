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
    ListNode* middleNode(ListNode* head) {
        
        int c=0;
        ListNode* temp=head;

        while(temp!=NULL){
            c++;
            temp=temp->next;
        }
       // temp=head;//reinitialisation bhi karsakte
               ListNode* q=head;

        for(int i=0;i<c/2;i++){
            q=q->next;
        }
        return q;

    }
};