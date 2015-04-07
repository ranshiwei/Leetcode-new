#include <iostream>
using namespace std;
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode *reverseBetween(ListNode *head, int m, int n) {
        if(m>=n||m==0||n==0)
            return head;
        ListNode *pre=new ListNode(0);
        bool flag=false;
        int i;
        if(m==1){
            pre->next=head;
            flag=true;
            i=1;
        }else{
            pre=head;
            i=2;
        }
        while(i<m&&pre->next!=NULL){
            pre=pre->next;
            i++;
        }
        ListNode *cur=pre->next;
        while(cur->next!=NULL&&i!=n){
            ListNode *post=cur->next;
            cur->next=post->next;
            post->next=pre->next;
            pre->next=post;
            i++;
        }
        return flag ? pre->next:head;
    }
};
int main(){
	ListNode *head=new ListNode(1);
	ListNode *s1=new ListNode(2);
	ListNode *s5=new ListNode(3);
	ListNode *s2=new ListNode(4);
	ListNode *s3=new ListNode(5);
//	ListNode *s4=new ListNode(2);
	
	head->next=s1;
	s1->next=s5;
	s5->next=s2;
	s2->next=s3;
//	s3->next=s4;
	Solution s;
	ListNode *result=s.reverseBetween(head,2,4);
	while(result!=NULL){
		cout<<result->val<<endl;
		result=result->next;
	}
}
