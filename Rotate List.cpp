/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *rotateRight(ListNode *head, int k) {
        if(k<=0||head==NULL) return head;
        ListNode *cur,*pre;
        cur=head;
        pre=head;
        int i=0;
        int len=0;
        while(cur!=NULL){
            cur=cur->next;
            len++;
        } 
        cur=head;
        if(k>len)
            k%=len;
        while(i<k&&pre->next!=NULL){
            i++;
            pre=pre->next;
        }
        if(i==k&&k!=0){
            while(pre->next!=NULL){
                cur=cur->next;
                pre=pre->next;
            }
            ListNode *t=cur->next;
            pre->next=head;
            head=t;
            cur->next=NULL;
        }
    return head;
    }
    
};
